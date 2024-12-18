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

import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.concurrent.CompletableFuture;

public class WebClient {
    //El unico atributo de la clase es la instancia de un HttpClient que esta en las librerias de java
    private HttpClient client;

    //El constructor crea al HttpClient y define los principales parametros como son la version
    //del protocolo http a utilizar.
    public WebClient() {
        this.client = HttpClient.newBuilder()
                .version(HttpClient.Version.HTTP_1_1)
                .build();
    }
    //Metodo sendTask: Recibe la url y los bytes que conformaran la peticion para poder formar
    //el request, para luego enviarla de manera asincrona
    public CompletableFuture<byte[]> sendTask(String url, byte[] requestPayload) {
        HttpRequest request = HttpRequest.newBuilder()
		.uri(URI.create(url))
		.header("X-Debug","true")
                .POST(HttpRequest.BodyPublishers.ofByteArray(requestPayload))
                .build();

        return client.sendAsync(request, HttpResponse.BodyHandlers.ofByteArray())
		.thenApply(response -> { System.out.println(response.headers());
					 return response;})
		.thenApply(response -> { System.out.println(response.version());
					 return response;})
		.thenApply(response -> { System.out.println(response.uri());
					 return response;})
                .thenApply(response -> {return response.body();});
    }
}
