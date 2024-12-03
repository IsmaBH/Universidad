public class Coordenada{
	private double x, y;
	public Coordenada(double x, double y){
		this.x = x;
		this.y = y;
	}
	//Metodo getter de x
	public double abcisa() {return this.x;}
	//Metodo getter de y
	public double ordenada() {return this.y;}
	//Sobreescritura del metodo toString
	@Override
	public String toString(){
		return "["+this.x+","+this.y+"]";
	}
}
