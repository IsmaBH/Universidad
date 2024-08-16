public class Triangulo extends Figura{
	private double base;
	private double altura;
	//Constructor
	//Se invoca el constructor de la clase base
	public Triangulo(double b, double a){
		super("Triangulo");
		base = b;
		altura = a;
	}
	public Triangulo(){
		this(10.0,10.0);
	}
	//La clase triangulo proporciona su propia definicion de
	//los metodos dibujar y obtenerArea
	public double obtenerArea(){
		return(base * altura / 2);
	}
	public String dibuja(){
		return("Soy un triangulo de base: "+base+" y altura: "+altura);
	}
}