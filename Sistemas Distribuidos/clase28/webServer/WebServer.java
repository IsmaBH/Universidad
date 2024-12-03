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
    private static final String TASK_ENDPOINT = "/multiplica";
    private static final String STATUS_ENDPOINT = "/status";
    //Puerto para realizar conexiones con clientes
    private final int port;
    //Implementando un servidor con la clase HttpServer
    private HttpServer server;
    private WebClient interfazCliente;
    //private WebClient interfazCliente;
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
	this.interfazCliente = new WebClient();
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
    //Asigna un método manejador a los endpoints
        statusContext.setHandler(this::handleStatusCheckRequest);
        taskContext.setHandler(this::handleTaskRequest);
    //Se proveen 8 hilos para que el servidor trabaje
        server.setExecutor(Executors.newFixedThreadPool(8));
    //Se inicia el servidor como hilo en segundo plano
        server.start();
    }

    //Manejador del endpoint task
    //HttpExchange contiene todo lo relacionado con la transacción HTTP actual
    private void handleTaskRequest(HttpExchange exchange) throws IOException {
    //Se verifica si se solicitó un método POST
    /*
        if (!exchange.getRequestMethod().equalsIgnoreCase("post")) {
            exchange.close();
            return;
        }
    */
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
    //Se obtiene la url de la peticion
    	String query = getQueryParam(exchange);
	System.out.println("Factores recibidos "+query);
    //Se recupera el cuerpo del mensaje de la transacción HTTP
        byte[] requestBytes = query.getBytes();
    //Se envían los números recibidos al servidor de procesamiento mediante el objeto client mediante http
        byte[] responseBytes = interfazCliente.sendTask("http://127.0.0.1:8082/task", requestBytes).join().getBytes();
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
    //Funcion que abstrae los parametros obtenidos del url
    private static String getQueryParam(HttpExchange httpExchange){
	    String query = httpExchange.getRequestURI().getQuery();
	    if(query != null){
		    String[] parte1 = query.split("&");
		    String[] parte2 = parte1[0].split("=");
		    String[] parte3 = parte1[1].split("=");
		    if(parte2[1].matches(".*[0-9].*") && parte3[1].matches(".*[0-9].*")){
			    String resultado = parte2[1] + "," + parte3[1];
			    return resultado;
		    }
	    }
	    return null;
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
}
