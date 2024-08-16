//Codigo para crear una ventana con titulo
import javax.swing.*;
public class RectangleProgram extends JFrame{
	private static final int WIDTH = 400;
	private static final int HEIGHT = 300;
	//En este contructor definimos todos los parametros que tendra nuestra ventana
	public RectangleProgram(){
		setTitle("Area y perimetro de un Rectangulo");
		setSize(WIDTH,HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	//Con este metodo main vamos a probar el funcionamiento de la ventana
	public static void main(String[] args) {
		RectangleProgram rectProg = new RectangleProgram();
	}
}