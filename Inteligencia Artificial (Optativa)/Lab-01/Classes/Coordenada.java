public class Coordenada{
	//atributo
	private int x;
	private int y;
	//COnstructor
	public Coordenada(int coorX,int coorY){
		this.x = coorX;
		this.y = coorY;
	}
	//Metodos
	public int getX(){
		return this.x;
	}
	public int getY(){
		return this.y;
	}
	public void mostrar(){
		System.out.println(this.x+","+this.y);
	}
}