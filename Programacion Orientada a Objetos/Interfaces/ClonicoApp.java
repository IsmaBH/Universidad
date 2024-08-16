public class ClonicoApp{
	public static void main(String[] args) {
		Punto punto = new Punto(20,30);
		Punto pCopia = (Punto)punto.clone();
		System.out.println("Punto "+punto);
		System.out.println("Copia "+pCopia);

		Rectangulo rect = new Rectangulo(new Punto(0,0), 4, 5);
		Rectangulo rCopia = (Rectangulo)rect.clone();
		System.out.println("Rectangulo "+rect);
		System.out.println("Copia "+rCopia);

		try{
			//Espera a la pulsacion de una tecla y luego retorno
			System.in.read();
		}catch(Exception e){}
	}
}