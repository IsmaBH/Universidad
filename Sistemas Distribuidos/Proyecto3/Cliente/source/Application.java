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

/*
 * PROYECTO 3
 * AUTOR: DIEGO ISMAEL BARON HERNANDEZ
 * GRUPO: 4CM14
 */
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Application {
    public static void main(String[] args) {
	//Declaramos la variables a usar
	String WORKER_ADDRESS_1 = "http://";
	String WORKER_ADDRESS_2 = "http://";
	String WORKER_ADDRESS_3 = "http://";
	ArrayList<String> words = new ArrayList<String>();
	ArrayList<String> addresses = new ArrayList<String>();
	//Creamos el objeto Aggregator
        Aggregator aggregator = new Aggregator();
	//Preparamos las direcciones de los servidores
	WORKER_ADDRESS_1 = WORKER_ADDRESS_1 + args[0] + ":80/searchword";
	WORKER_ADDRESS_2 = WORKER_ADDRESS_2 + args[1] + ":80/searchword";
	WORKER_ADDRESS_3 = WORKER_ADDRESS_3 + args[2] + ":80/searchword";
	//Se forma un ArrayList de direcciones para facilitar el posterior uso
	addresses.add(WORKER_ADDRESS_1);
	addresses.add(WORKER_ADDRESS_2);
	addresses.add(WORKER_ADDRESS_3);
	//Se deben leer los datos restantes que seran las palabras solicitadas
	//Esto se hace mediante un ciclo for hasta que se terminen los argumentos
	//y guardamos los datos en un ArrayList
	for(int i = 3; i < args.length; i++){
		words.add(args[i]);
	}
	//El siguiente paso es enviar de 3 en tres las palabras a los servidores y cuando se reciba la respuesta de uno
	//enviar la siguiente palabra a buscar, sucesivamente con cada uno hasta que se terminen las palabras
	String task;
	int worker = 0;
	for(int j = 0; j < words.size(); j++){
		task = words.get(j);
		System.out.println(task);
		if(worker == 2){
			worker = 0;
		}else{
			worker++;
		}
		List<String> results = aggregator.sendTasksToWorkers(Arrays.asList(addresses.get(worker)), Arrays.asList(task));
		for(String result : results){
			System.out.println(result);
		}
	}
    }
}
