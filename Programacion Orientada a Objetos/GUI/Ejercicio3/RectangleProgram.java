import javax.swing.*;
import java.awt.*; //Clase Container

public class RectangleProgram extends JFrame{
	private static final int WIDTH = 400;
	private static final int HEIGHT = 300;
	//Definimos las etiquetas
	private JLabel lenghtL, widthL, areaL, perimeterL;
	//Definimos los campos de texto
	private JTextField lenghtTF, widthTF, areaTF, perimeterTF;
	//Constructor
	public RectangleProgram(){
		setTitle("Area y perimetro de un rectangulo");
		//Nota: el nombre de las variables que acompañan a SwingConstants deben ser
		//Todas las letras en mayusculas dado que asi lo dice la documentacion de swing
		lenghtL = new JLabel("Ingresa la altura",SwingConstants.RIGHT);
		widthL = new JLabel("Ingresa el ancho",SwingConstants.RIGHT);
		areaL = new JLabel("Area",SwingConstants.RIGHT);
		perimeterL = new JLabel("Perimetro",SwingConstants.RIGHT);
		//Instanciamos los campos de texto
		lenghtTF = new JTextField(10);
		widthTF = new JTextField(10);
		areaTF = new JTextField(10);
		perimeterTF = new JTextField(10);
		//Aqui se crea la cuadricula y se le asignan un elemento a cada espacio de la misma
		//Tambien se agregan los cuadros de texto
		Container pane = getContentPane();
		pane.setLayout(new GridLayout(4,2));
		pane.add(lenghtL); //Renglon 1, Columna 1
		pane.add(lenghtTF); //Renglon 1, Columna 2
		pane.add(widthL); //Renglon 2, Columna 1
		pane.add(widthTF); //Renglon 2, Columna 2
		pane.add(areaL); //Renglon 3, Columna 1
		pane.add(areaTF); //Renglon 3, Columna 2
		pane.add(perimeterL); //Renglon 4, Columna 1
		pane.add(perimeterTF); //Renglon 4, Columna 2
		//Aqui se definen las dimensiones de la ventana
		setSize(WIDTH,HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	//Con este metodo main probamos el funcionamiento de la ventana
	public static void main(String[] args) {
		RectangleProgram rectProg = new RectangleProgram();
	}
}