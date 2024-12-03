/*
 * PROYECTO 3
 * AUTOR: DIEGO ISMAEL BARON HERNANDEZ
 * GRUPO: 4CM14
 */
import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpContext;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpServer;
import java.io.IOException;
import java.io.OutputStream;
import java.math.BigInteger;
import java.net.InetSocketAddress;
import java.util.Arrays;
import java.util.concurrent.Executors;
import java.util.Random;
import java.io.ByteArrayOutputStream;
import java.io.*;
import java.util.Scanner;
public class WebServer {
    //Declaración de endpoints
    private static final String TASK_ENDPOINT = "/task";
    private static final String STATUS_ENDPOINT = "/status";
    private static final String SEARCHIPN_ENDPOINT = "/searchipn";
    private static final String SEARCHWORD_ENDPOINT = "/searchword";
    //Puerto para realizar conexiones con clientes
    private final int port;
    //Implementando un servidor con la clase HttpServer
    private HttpServer server;
    public static void main(String[] args) {
    //Se coloca puerto por default en caso de que no se envíe por línea de comandos
        int serverPort = 8080;
        if (args.length == 1) {
            serverPort = Integer.parseInt(args[0]);
        }
    //Instancia de WebServer
        WebServer webServer = new WebServer(serverPort);
    //Ejecutando método startServer para iniciar configuración del servidor
    webServer.startServer();
        System.out.println("Servidor escuchando en el puerto " + serverPort);
    }
    //Constructor
    public WebServer(int port) {
        this.port = port;
    }
    public void startServer() {
        try {
        //Creando instancia de la clase HttpServer
        //Recibe un socket y el tamaño de la lista de solicitudes pendientes para el servidor
        //Al colocar un cero se deja la decisión al servidor
            this.server = HttpServer.create(new InetSocketAddress(port), 0);
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
    //Creando objetos HttpContext
        HttpContext statusContext = server.createContext(STATUS_ENDPOINT);
        HttpContext taskContext = server.createContext(TASK_ENDPOINT);
        HttpContext searchContext = server.createContext(SEARCHIPN_ENDPOINT);
	HttpContext wordContext = server.createContext(SEARCHWORD_ENDPOINT);
    //Asigna un método manejador a los endpoints
        statusContext.setHandler(this::handleStatusCheckRequest);
        taskContext.setHandler(this::handleTaskRequest);
        searchContext.setHandler(this::handleSearchRequest);
	wordContext.setHandler(this::handleWordRequest);
    //Se proveen 8 hilos para que el servidor trabaje
        server.setExecutor(Executors.newFixedThreadPool(8));
    //Se inicia el servidor como hilo en segundo plano
        server.start();
    }
    //Manejador del endpoint task
    //HttpExchange contiene todo lo relacionado con la transacción HTTP actual
    private void handleTaskRequest(HttpExchange exchange) throws IOException {
    //Se verifica si se solicitó un método POST
        if (!exchange.getRequestMethod().equalsIgnoreCase("post")) {
            exchange.close();
            return;
        }
    //Se recupera los Headers, busscando con claves X-Test para generar respuesta conocida
        Headers headers = exchange.getRequestHeaders();
        if (headers.containsKey("X-Test") && headers.get("X-Test").get(0).equalsIgnoreCase("true")) {
            String dummyResponse = "123\n";
            sendResponse(dummyResponse.getBytes(), exchange);
            return;
        }
    //Se busca clave X-Debug para verificar estado del servidor
        boolean isDebugMode = false;
        if (headers.containsKey("X-Debug") && headers.get("X-Debug").get(0).equalsIgnoreCase("true")) {
            isDebugMode = true;
        }
    //Calculando tiempo que tardó el proceso completo
        long startTime = System.nanoTime();
    //Se recupera el cuerpo del mensaje de la transacción HTTP
        byte[] requestBytes = exchange.getRequestBody().readAllBytes();
    //Se envían los números recibidos para calcular una operación con calculateResponse
        byte[] responseBytes = calculateResponse(requestBytes);
    //Se termina el cálculo y se toma el tiempo final
        long finishTime = System.nanoTime();
    //Si se activó el modo Debug se imprime el tiempo que tardó
        if (isDebugMode) {
            String debugMessage = String.format("La operacion tomo %d nanosegundos", finishTime - startTime);
            //Se coloca el tiempo en el header X-Debug-Info
        exchange.getResponseHeaders().put("X-Debug-Info", Arrays.asList(debugMessage));
        }
    //Se envía respuesta al cliente
        sendResponse(responseBytes, exchange);
    }
    //Método para multiplicar dos números BigInteger
    private byte[] calculateResponse(byte[] requestBytes) {
        String bodyString = new String(requestBytes);
        String[] stringNumbers = bodyString.split(",");
        BigInteger result = BigInteger.ONE;
        for (String number : stringNumbers) {
            BigInteger bigInteger = new BigInteger(number);
            result = result.multiply(bigInteger);
        }
        return String.format("El resultado de la multiplicación es %s\n", result).getBytes();
    }
    //Se analiza si la petición es GET para devolver que el servidor está vivo
    private void handleStatusCheckRequest(HttpExchange exchange) throws IOException {
        if (!exchange.getRequestMethod().equalsIgnoreCase("get")) {
            exchange.close();
            return;
        }
        String responseMessage = "El servidor está vivo\n";
        sendResponse(responseMessage.getBytes(), exchange);
    }
    private void sendResponse(byte[] responseBytes, HttpExchange exchange) throws IOException {
    //Agrega estatus code 200 de éxito y longitud de la respuesta
        exchange.sendResponseHeaders(200, responseBytes.length);
    //Se escribe en el cuerpo del mensaje
        OutputStream outputStream = exchange.getResponseBody();
    //Se envía al cliente por medio del Stream
        outputStream.write(responseBytes);
        outputStream.flush();
        outputStream.close();
        exchange.close();
    }
    //Manejador del endpoint searchipn
    private void handleSearchRequest(HttpExchange exchange) throws IOException {
    //Se verifica si se solicitó un método POST
        if (!exchange.getRequestMethod().equalsIgnoreCase("post")) {
            exchange.close();
            return;
        }
    //Se busca clave X-Debug para verificar estado del servidor
        Headers headers = exchange.getRequestHeaders();
    boolean isDebugMode = false;
        if (headers.containsKey("X-Debug") && headers.get("X-Debug").get(0).equalsIgnoreCase("true")) {
            isDebugMode = true;
        }
    //Calculando tiempo que tardó el proceso completo
        long startTime = System.nanoTime();
    //Se recupera el cuerpo del mensaje de la transacción HTTP
    //Este va a contener la cantidad de tokens aleatorios
        byte[] requestBytes = exchange.getRequestBody().readAllBytes();
    //Se envían los números recibidos para calcular una operación con calculateResponse
        byte[] responseBytes = calculateSearchResponse(requestBytes);
    //Se termina el cálculo y se toma el tiempo final
        long finishTime = System.nanoTime();
    //Si se activó el modo Debug se imprime el tiempo que tardó
        if (isDebugMode) {
            String debugMessage = String.format("La operacion tomo %d nanosegundos", finishTime - startTime);
            //Se coloca el tiempo en el header X-Debug-Info
        exchange.getResponseHeaders().put("X-Debug-Info", Arrays.asList(debugMessage));
            // Concatenando responseBytes y el tiempo que tardó en finalizar la petición
            byte[] timeBytes = String.format("La operacion tomo %d nanosegundos", finishTime - startTime).getBytes();
            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            outputStream.write(responseBytes);
            outputStream.write(timeBytes);
            responseBytes = outputStream.toByteArray();
        }
    //Se envía respuesta al cliente
        sendResponse(responseBytes, exchange);
    }

    //Método para buscar cadena en tokens de cadenota
    private byte[] calculateSearchResponse(byte[] requestBytes) {
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
        return String.format("\nLa cantidad de veces que se encontró la cadena '" + cadena + "' fue: %d\n\n", apariciones).getBytes();
    }
    //Manejador del endpoint searchword
    private void handleWordRequest(HttpExchange exchange) throws IOException{
	    //Se verifica si se solicito un metodo POST
	    if(!exchange.getRequestMethod().equalsIgnoreCase("post")){
		    exchange.close();
		    return;
	    }
	    //Se busca clase X-Debug para verivicar el estado del servidor
	    Headers headers = exchange.getRequestHeaders();
	    boolean isDebugMode = false;
	    if (headers.containsKey("X-Debug") && headers.get("X-Debug").get(0).equalsIgnoreCase("true")) {
		    isDebugMode = true;
	    }
	    //Se empieza a calcular el tiempo que tarda el proceso
	    long startTime = System.nanoTime();
	    //Se recupera el cuerpo del mensaje de la transaccion HTTP
	    //Este contendra la palabra recivida a buscar
	    byte[] requestBytes = exchange.getRequestBody().readAllBytes();
	    //Se envian los bytes de la palabra recivida para buscar con searchWord
	    byte[] responseBytes = searchWordResponse(requestBytes);
	    //Se toma el tiempo final
	    long finishTime = System.nanoTime();
	    //Si se activo el modo Debug se imprime el tiempo que tardo
	    if(isDebugMode){
		    String debugMessage = String.format("La operacion tomo %d nanosegundos", finishTime - startTime);
		    //Se coloca el tiempo en el header X-Debug-Info
		    exchange.getResponseHeaders().put("X-Debug-Info", Arrays.asList(debugMessage));
		    //Concatenando responseBytes y el tiempo que tardo en finalizar la peticion
		    byte[] timeBytes = String.format("La operacion tomo %d nanosegundos", finishTime - startTime).getBytes();
		    ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		    outputStream.write(responseBytes);
		    outputStream.write(timeBytes);
		    responseBytes = outputStream.toByteArray();
	    }
	    //Se envia respuesta al cliente
	    sendResponse(responseBytes,exchange);
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
}
