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

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.concurrent.CompletableFuture;

public class WebClient {
    private HttpClient client;

    public WebClient() {
        this.client = HttpClient.newBuilder()
                .version(HttpClient.Version.HTTP_1_1)
                .build();
    }

    public CompletableFuture<byte[]> sendTask(String url, byte[] requestPayload) {
        HttpRequest request = HttpRequest.newBuilder()
                .POST(HttpRequest.BodyPublishers.ofByteArray(requestPayload))
                .uri(URI.create(url))
                .build();

        return client.sendAsync(request, HttpResponse.BodyHandlers.ofByteArray())	
                .thenApply(HttpResponse::body);
    }

    //Metodo que sirve para enviar tareas a mas de un trabajador
    public List<byte[]> sendTasksToWorkers(List<String> workersAddrs, List<String> tasks){
	    //Se usa la clase CompletableFuture para el manejo de la comunicacion asincrona
	    //esto con la finalidad de que se permita la ejecucion de codigo bloqueante, que
	    //se reactiva cuando los datos se encuentren disponibles en el futuro.
	    CompletableFuture<byte[]>[] futures = new CompletableFuture[workersAddrs.size()];
	    //Se itera sobre las listas de datos recibidos y se convierten las tareas a un 
	    //formato de bytes para usar el metodo sendTask.
	    for(int i = 0; i < workersAddrs.size(); i++){
		    String workerAddr = workersAddrs.get(i);
		    byte[] task = tasks.get(i).getBytes();
		    futures[i] = sendTask(workerAddr, task);
	    }
	    //Obtenemos la lista de resultados
	    List<byte[]> results = Stream.of(futures).map(CompletableFuture::join).collect(Collectors.toList());
	    return results;
    }
}
