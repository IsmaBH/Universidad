public class Circulo extends Figura{
	private double radio;
	private static final double pi = 3.1416;
	//Constructor
	//Invocando el constructor de la clase base
	public Circulo(double r){
		super("Circulo");
		radio = r;
	}
	public Circulo(){
		this(10.0);
	}
	public double obtenerArea(){
		return (pi * radio * radio);
	}
	public String dibuja(){
		return("Soy un circulo con radio: "+radio);
	}
}