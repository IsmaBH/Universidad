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

import java.util.Arrays;
import java.util.List;
import java.io.*;

class Demo implements java.io.Serializable{
	public int a;
	public int b;

	//Defeault constructor
	public Demo(int a, int b){
		this.a = a;
		this.b = b;
	}
}
//Clase principal
public class Application {
    //Se definen las direcciones de los servidores a consultar
    private static final String WORKER_ADDRESS_1 = "http://localhost:8081/task";
    //private static final String WORKER_ADDRESS_2 = "http://localhost:8082/task";
    
    public static void main(String[] args) {
        Aggregator aggregator = new Aggregator();
	//Creamos el objeto demo
	Demo object = new Demo(2022,45);
	//Imprimimos el contenido del objeto antes de serializarlo
	System.out.println("a = " + object.a);
	System.out.println("b = " + object.b);
	//Pasamos el objeto a la serializacion
	byte[] serializado = SerializationUtils.serialize(object);
	//El metodo sendTaskTo Workers tomara los datos definidos anteriormente convertidos en listas
	//Y los enviara a sus respectivos servidores para luego esperar la respuesta de cada uno
        List<String> results = aggregator.sendTasksToWorkers(Arrays.asList(WORKER_ADDRESS_1),Arrays.asList(serializado));
	//Al final se itera sobre la lista de resultados y los muestra en pantalla
        for (String result : results) {
            System.out.println(result);
        }
    }
}
