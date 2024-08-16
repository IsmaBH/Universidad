public class Rectangulo extends Figura{
	private double base;
	private double altura;
	//Constructor
	//Invocacion del constructor de la clase base
	public Rectangulo(double b, double a){
		super("Rectangulo");
		base = b;
		altura = a;
	}
	public Rectangulo(){
		this(10.0,10.0);
	}
	//La clase rectangulo proporciona su propia definicion
	//de los metodos dibujar y obtenerArea
	public double obtenerArea(){
		return (base * altura);
	}
	public String dibuja(){
		return("Soy un rectangulo de base: "+base+" y altura: "+altura);
	}
}