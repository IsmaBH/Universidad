public class Rectangulo{
	private Coordenada superiorIzq, inferiorDer;

	public Rectangulo(){
		superiorIzq = new Coordenada(0,0);
		inferiorDer = new Coordenada(0,0);
	}
	public Rectangulo(Coordenada c1, Coordenada c2){
		superiorIzq = c1;
		inferiorDer = c2;
	}
	//Metodo getter de la coordenada superior izquierda
	public Coordenada superiorIzquierda() {return this.superiorIzq;}
	//Metodo getter de la coordenada inferior derecha
	public Coordenada inferiorDerecha() {return this.inferiorDer;}
	//Sobreescritura del metodo toString
	@Override
	public String toString(){
		return "Esquina superior izquierda: "+this.superiorIzq+"\tEsquina inferior derecha: "+this.inferiorDer+"\n";
	}
}
