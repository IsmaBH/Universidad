//Autor: Diego Ismael Baron Hernandez
public class EjerciciosSerie5{
	public static void main(String args[]) {
		int n = Integer.parseInt(args[0]);
		byte[] cadenota = new byte[n*4];
		long tiempoInicial = System.nanoTime();
		for(int i = 0; i < n*4; i++){
			if(((i+1)%4) == 0){
				cadenota[i] = (byte) 32;
			} else{
				cadenota[i] = (byte) ((Math.random()*(65-90)) + 90);
			}
		}
		int contador = 0;
		for(int j = 0; j < n*4; j++){
			if(cadenota[j] == (int) 73 && cadenota[j+1] == (int) 80 && cadenota[j+2] == (int) 78){
				contador++;
			}
			j += 4;
		}
		long tiempoFinal = System.nanoTime();
		long tiempo = (tiempoFinal - tiempoInicial);
		System.out.println("Incidencias: " + contador);
		System.out.println("Tiempo de ejecucion en nanosegundos: "+tiempo);
	}
}
