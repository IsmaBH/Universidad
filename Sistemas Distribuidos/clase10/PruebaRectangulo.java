public class PruebaRectangulo{
	public static void main(String[] args){
		Rectangulo rect1 = new Rectangulo(new Coordenada(2,3),new Coordenada(5,1));
		double ancho, alto;

		System.out.println("Calculando el area de un rectangulo dadas sus coordenadas en un plano cartesiano: ");
		System.out.println(rect1);
		alto = rect1.superiorIzquierda().ordenada() - rect1.inferiorDerecha().ordenada();
		ancho = rect1.inferiorDerecha().abcisa() - rect1.superiorIzquierda().abcisa();
		System.out.println("El area del rectangulo es = "+ancho*alto);
	}
}
