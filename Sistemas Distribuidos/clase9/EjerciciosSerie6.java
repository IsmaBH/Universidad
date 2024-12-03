//Autor: Diego Ismael Baron Hernandez
import java.util.*;

public class EjerciciosSerie6{
	public static void main(String[] args){
		int n = Integer.parseInt(args[0]);
		StringBuilder cadenota = new StringBuilder(n*4);
		long tiempoInicial = System.nanoTime();
		for(int i = 0; i < n*4; i++){
			if(((i+1)%4) == 0){
				cadenota.append((byte)32);
			}else{
				cadenota.append((byte)((Math.random()*(65-90))+90));
			}
		}
		int contador = 0;
		int indice = 0;
		for(int j = 0; j < n*4; j++){
			indice = cadenota.indexOf("738078",j);
			if(indice != -1){
				indice += 4;
				contador++;
				j = indice;
			}else{
				j += 4;
			}
		}
		long tiempoFinal = System.nanoTime();
		long tiempo = tiempoFinal - tiempoInicial;
		System.out.println("Incidencias: " + contador);
		System.out.println("Tiempo de ejecucion en nanosegundos: " + tiempo);
	}
}
