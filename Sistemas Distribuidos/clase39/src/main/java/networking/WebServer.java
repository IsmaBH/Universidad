/*
 *  MIT License
 *
 *  Copyright (c) 2019 Michael Pogrebinsky - Distributed Systems & Cloud Computing with Java
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

package networking;

import com.sun.net.httpserver.HttpContext;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpServer;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.PropertyNamingStrategy;
import model.frontend.FrontendSearchRequest;
import model.frontend.FrontendSearchResponse;
import networking.WebClient;
import search.Busqueda;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.util.concurrent.Executors;
import java.util.StringTokenizer;
import java.util.List;
import java.util.Arrays;
import java.util.Random;
import java.util.ArrayList;
import java.io.File;
import java.text.ParseException;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class WebServer {
    //Declaracion de los endpoints del servidor (Escalable)
    private static final String STATUS_ENDPOINT = "/status";
    private static final String HOME_PAGE_ENDPOINT = "/";
    private static final String HOME_PAGE_UI_ASSETS_BASE_DIR = "/ui_assets/";
    private static final String ENDPOINT_PROCESS = "/procesar_datos";
    private static final String SEARCH_MOTOR_ENDPOINT = "/busqueda";
    //Se define las direcciones de los servidores de procesamiento
    private static final String WORKER_ADDR_1 = "http://127.0.0.1:9001/procesar_datos";
    private static final String WORKER_ADDR_2 = "http://127.0.0.1:9002/procesar_datos";
    private static final String WORKER_ADDR_3 = "http://127.0.0.1:9003/procesar_datos";
    ///Atributos de la clase
    private final int port;
    private HttpServer server;
    private final ObjectMapper objectMapper;
    private WebClient interfazCliente;
    //Declaracion del objeto file de la carpeta de los libros
    private static final String ruta = System.getProperty("user.dir") + "/src/main/java/search/LIBROS_TXT";
    private static final File folder = new File(ruta);
    //Constructor
    public WebServer(int port) {
        this.port = port;
        this.objectMapper = new ObjectMapper();
        this.objectMapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
        this.objectMapper.setPropertyNamingStrategy(PropertyNamingStrategy.SNAKE_CASE);
	this.interfazCliente = new WebClient();
    }
    //Metodo startServer: Inicializa los parametros del servidor para su arranque
    public void startServer() {
	//Creando instancia de la clase HttpServer
	//Recibe un socket y el tamaño de la lista de las solicitudes pendientes para el servidor
	//Al colocar un cero se deja la decision al servidor
        try {
            this.server = HttpServer.create(new InetSocketAddress(port), 0);
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
	//Declaracion del context asociado a cada uno de los endpoints del servidor (Escalable)
        HttpContext statusContext = server.createContext(STATUS_ENDPOINT);
        HttpContext taskContext = server.createContext(ENDPOINT_PROCESS);
	HttpContext searchContext = server.createContext(SEARCH_MOTOR_ENDPOINT);
	//Asigna un metodo manejador para cada uno de los endpoints (Escalable)
        statusContext.setHandler(this::handleStatusCheckRequest);
        taskContext.setHandler(this::handleTaskRequest);
	searchContext.setHandler(this::handleSearchRequest);
        //Declaracion especial para el contexto de la pagina principal (Solicitud de recursos)
        HttpContext homePageContext = server.createContext(HOME_PAGE_ENDPOINT);
        homePageContext.setHandler(this::handleRequestForAsset);
	//Se proveen 8 hilos para que el servidor trabaje
        server.setExecutor(Executors.newFixedThreadPool(8));
	//Se inicia el servidor como hilo en segundo plano
        server.start();
    }
    
    //Manejador del endpoint HOME_PAGE
    private void handleRequestForAsset(HttpExchange exchange) throws IOException {
        if (!exchange.getRequestMethod().equalsIgnoreCase("get")) {
            exchange.close();
            return;
        }

        byte[] response;

        String asset = exchange.getRequestURI().getPath();

        if (asset.equals(HOME_PAGE_ENDPOINT)) {
            response = readUiAsset(HOME_PAGE_UI_ASSETS_BASE_DIR + "index.html");
        } else {
            response = readUiAsset(asset);
        }
        addContentType(asset, exchange);

        sendResponse(response, exchange);
    }

    private byte[] readUiAsset(String asset) throws IOException {
        InputStream assetStream = getClass().getResourceAsStream(asset);
        if (assetStream == null) {
            return new byte[]{};
        }

        return assetStream.readAllBytes();
    }

    private static void addContentType(String asset, HttpExchange exchange) {
        String contentType = "text/html";
        if (asset.endsWith("js")) {
            contentType = "text/javascript";
        } else if (asset.endsWith("css")) {
            contentType = "text/css";
        }
        exchange.getResponseHeaders().add("Content-Type", contentType);
    }
    
    //Manejador del endpoint Task este recibe la peticion de busqueda cuando el cliente web presiona el boton "enviar"
    //Este es el metodo que se modificara y donde sera util la instancia de WebClient hecha anteriormente.
    private void handleTaskRequest(HttpExchange exchange) throws IOException {
	//La peticion se hace por medio de un metodo post
	//Si se hace por cualquier otro metodo se rechaza la conexión
        if (!exchange.getRequestMethod().equalsIgnoreCase("post")) {
            exchange.close();
            return;
        }
	//Dentro del try se llevan acabo las operaciones que realizara el servidor
	//Aqui se pregunta por el numero de puerto que usa el servidor actual
	//Si el puerto es 9000 entonces es el servidor de direccionamiento por lo tanto
	//no ejecutara la busqueda si no que dividira el trabajo y enviara las tareas
	//a los demas servidores de procesamiento y recibira la respuesta de estos para
	//mostrarlos al cliente.
        try {
    	    if(this.port == 9000){
		    //Lo primero es leer los datos recibidor por el cliente web
		    FrontendSearchRequest frontendSearchRequest = objectMapper.readValue(exchange.getRequestBody().readAllBytes(), FrontendSearchRequest.class);
		    //System.out.println("Los datos recibidos por el servidor web son: " + frontendSearchRequest.getSearchQuery());
		    //Lo siguiente sera dividir el trabajo de buscar la cadena solicitada en 1,757,600 tokens entre los servidores disponibles (en este caso 3)
		    //El resultado seria 585,866.666 tokens por servidor pero se redondeara hacia arriba quedando en 585,867 tokens por servidor.
		    long startTime = System.nanoTime();
		    String query = "585867" + "," + frontendSearchRequest.getSearchQuery();
		    //Una vez formadas las peticiones se enviaran a cada uno de los servidores de manera asincrona con el metodo sendTask() de la clase WebClient
		    //Y se espera la respuesta de todos para mostrarlos en pantalla con la forma: IP: 192.68.34.78     coincidencias:98      tiempo: 532020930 ns
		    List<byte[]> resultados = interfazCliente.sendTasksToWorkers(Arrays.asList(WORKER_ADDR_1,WORKER_ADDR_2,WORKER_ADDR_3), Arrays.asList(query,query,query));
		    //Estas son las listas que se llenaran con los resultados
		    String uri[] = {WORKER_ADDR_1,WORKER_ADDR_2,WORKER_ADDR_3};
		    String score[] = new String[3];
		    String tiempo[] = new String[3];
		    //Se itera sobre la lista de resultados para formar las listas de resultados
		    for(int i = 0; i < resultados.size(); i++){
			    String resultado = new String(resultados.get(i));
			    String[] datos = resultado.split(",");
			    score[i] = datos[0];
			    tiempo[i] = datos[1];
		    }
		    //Ahora enviamos las listas recolectadas hacia el cliente
		    FrontendSearchResponse frontendSearchResponse = new FrontendSearchResponse(uri,score,tiempo);
		    byte[] responseBytes = objectMapper.writeValueAsBytes(frontendSearchResponse);
		    sendResponse(responseBytes, exchange);
	    }else{
		    //Se empieza tomando el tiempo aproximado del sistema
		    long startTime = System.nanoTime();
		    //Se leen los datos recibidos del servidor de direccionamiento
		    byte[] requestBytes = exchange.getRequestBody().readAllBytes();
		    //Se pasan los datos recibidos a la funcion que calcula las apariciones de la cadena
		    String resultado = calculateSearchResponse(requestBytes);
		    //Se toma el tiempo aproximado de termino del proceso
		    long finishTime = System.nanoTime();
		    long total = finishTime - startTime;
		    resultado = resultado + "," + String.valueOf(total);
		    byte[] responseBytes = resultado.getBytes();
		    //Se envia de regreso el resultado obtenido
		    sendResponse(responseBytes, exchange);
	    }		
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
    }

    //Método para buscar cadena en tokens de cadenota
    private String calculateSearchResponse(byte[] requestBytes) {
        //Separando parámetros recibidos
    	String bodyString = new String(requestBytes);
        String[] stringNumbers = bodyString.split(",");
    	//Convirtiendo parámetros al formato deseado
    	int n = Integer.parseInt(stringNumbers[0]);
    	String cadena = stringNumbers[1];
    	//Declaración de cadenota
    	StringBuilder cadenota = new StringBuilder();
    	Random rand = new Random();
    	//Inicializando cadenota con "n" tokens de letras aleatorias
    	int contador = 0;
    	for(int i = 0; i < n*4; i++)
        if(contador != 3){
            cadenota.append((char)(rand.nextInt(26) + 65));
            contador++;
        } else if(contador == 3 && i != (n*4-1)) {
            cadenota.append((char)32);
            contador = 0;
        }
    	//Buscando la cadena deseada y contando cantidad de apariciones
    	int apariciones = 0, buscar = 0;
    	while(buscar != -1){
        	buscar = cadenota.indexOf(cadena, buscar);
        	if(buscar != -1){
            		apariciones++;
            		buscar += 4;
        	}
    	}
        return String.format("%d",apariciones);
    }

    //Manejador del endpoint SEARCH_MOTOR
    //Este sera el metodo que se encargara de procesar las solicitudes de busqueda
    private void handleSearchRequest(HttpExchange exchange) throws IOException{
	    //Lo primero que se hace es comprobar que la peticion se reciba por un metodo
	    if(!exchange.getRequestMethod().equalsIgnoreCase("post")){
		    exchange.close();
		    return;
	    }
	    try{
		    if(this.port == 9000){
			    FrontendSearchRequest frontendSearchRequest = objectMapper.readValue(exchange.getRequestBody().readAllBytes(), FrontendSearchRequest.class);
			    System.out.println("Los datos recibidos son: " + frontendSearchRequest.getSearchQuery());
			    String[] frase = frontendSearchRequest.getSearchQuery().split(" ");
			    Busqueda busqueda = new Busqueda(frase);
			    busqueda.setLibros(folder);
			    busqueda.setNoLibros();
			    busqueda.setNtFrase();
			    System.out.println(busqueda.getNoLibros());
		    }else{
			    //Busqueda searchObj = new Busqueda(frontendSearchRequest.getSearchQuery().split(" "));
			    //searchObj.setLibros(folder);
		    }
	    }catch(IOException e){
		    e.printStackTrace();
		    return;
	    }
    }

    //Metodo para buscar la palabra en el archivo
    private byte[] searchWordResponse(byte[] requestBytes){
            //Dado que el unico parametro que se recibe es la palabra a buscar no hace falta separar los parametros
            String bodyString = new String(requestBytes);
            //Imprimimos la palabra a buscar
            System.out.println("La palabra a buscar es: "+ bodyString);
            //Declaramos la ruta en la que se encuentra el archivo base
            //Como se encuentra en el mismo directorio que el servidor solo hay que poner el nombre del archivo
            String ruta = "BIBLIA_COMPLETA.txt";
            //Variable auxiliar para la lectura de las lineas del archivo
            String linea;
            //Variable para el conteo de las ocurrecias
            int ocurrencias = 0;
            //Declaramos un try-catch en caso de que no se encuentre el archivo
            try{
                    //Se crea el objeto File asociado al fichero
                    File f = new File(ruta);
                    FileReader fr = new FileReader(f);
                    BufferedReader br = new BufferedReader(fr);
                    //Mientras no se llegue al final del fichero seguiremos buscando mas ocurrencias
                    while((linea = br.readLine()) != null){
                            //Separamos las palabras de la linea para poder comparar las palabras
                            String[] lineaAux = linea.split(" ");
                            //iteramos en el array de palabras
                            for(int i = 0; i < lineaAux.length; i++){
                                    //Si la palabra es igual aumentamos las ocurrencias
                                    if(lineaAux[i].equalsIgnoreCase(bodyString)){
                                            ocurrencias++;
                                    }
                            }
                    }
                    //Se cierra el archivo
                    fr.close();
            }catch(FileNotFoundException e){
                    System.out.println(e.toString());
            }catch(IOException a){
                    System.out.println(a);
            }
            //Se imprime el numero de ocurrencias
            System.out.println("Ocurrencias: " + ocurrencias);
            //Se retorna el formato de respuesta
            return String.format("\nLa cantidad de veces que se encontro la palabra fue: %d\n\n", ocurrencias).getBytes();
    }

    private void handleStatusCheckRequest(HttpExchange exchange) throws IOException {
        if (!exchange.getRequestMethod().equalsIgnoreCase("get")) {
            exchange.close();
            return;
        }

        String responseMessage = "El servidor está vivo\n";
        sendResponse(responseMessage.getBytes(), exchange);
    }

    private void sendResponse(byte[] responseBytes, HttpExchange exchange) throws IOException {
        exchange.sendResponseHeaders(200, responseBytes.length);
        OutputStream outputStream = exchange.getResponseBody();
        outputStream.write(responseBytes);
        outputStream.flush();
        outputStream.close();
    }
}
