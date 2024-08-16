abstract class Figura{
	private String nombre;
	//Los metodos abstractos no tienen definicion
	//Solamente deben ser declarados como abstractos
	abstract public double obtenerArea();
	abstract public String dibuja();
	//Constructor
	public Figura(String nomFigura){
		nombre = nomFigura;
	}
	//La referencia fig puede tomar como valor una
	//instancia de circulo, rectangulo, triangulo
	public boolean mayorQue(Figura fig){
		return(this.obtenerArea() > fig.obtenerArea());
	}
	public String toString(){
		return (nombre+" , "+ obtenerArea());
	}
}