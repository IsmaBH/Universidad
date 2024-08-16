import javax.swing.*;
import java.awt.*; //Clase Container

public class RectangleProgramTwo extends JFrame{
	private static final int WIDTH = 400;
	private static final int HEIGHT = 300;

	private JLabel lenghtL, widthL, areaL, perimeterL;
	//Constructor
	public RectangleProgramTwo(){
		setTitle("Area y perimetro de un rectangulo");
		//Nota: el nombre de las variables que acompañan a SwingConstants deben ser
		//Todas las letras en mayusculas dado que asi lo dice la documentacion de swing
		lenghtL = new JLabel("Ingresa la altura",SwingConstants.LEFT);
		widthL = new JLabel("Ingresa el ancho",SwingConstants.LEFT);
		areaL = new JLabel("Area",SwingConstants.LEFT);
		perimeterL = new JLabel("Perimetro",SwingConstants.LEFT);
		//Aqui se crea la cuadricula y se le asignan un elemento a cada espacio de la misma
		Container pane = getContentPane();
		pane.setLayout(new GridLayout(4,1));
		pane.add(lenghtL); //Renglon 1
		pane.add(widthL); //Renglon 2
		pane.add(areaL); //Renglon 3
		pane.add(perimeterL); //Renglon 4
		//Aqui se definen las dimensiones de la ventana
		setSize(WIDTH,HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	//Con este metodo main probamos el funcionamiento de la ventana
	public static void main(String[] args) {
		RectangleProgramTwo rectProg = new RectangleProgramTwo();
	}
}