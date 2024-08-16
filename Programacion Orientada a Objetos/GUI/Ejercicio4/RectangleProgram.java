import javax.swing.*;
import java.awt.*; //Clase Container
import java.awt.event.*;//Este es importante ya que contiene la interfaz ActionListener

public class RectangleProgram extends JFrame{
	private static final int WIDTH = 400;
	private static final int HEIGHT = 300;
	//Definimos las etiquetas
	private JLabel lenghtL, widthL, areaL, perimeterL;
	//Definimos los campos de texto
	private JTextField lenghtTF, widthTF, areaTF, perimeterTF;
	//Definimos lo que seran nuestros botones
	JButton calculateB, exitB;
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
		//Creamos nuestros botones
		JButton calculateB = new JButton("Calcular");
		JButton exitB = new JButton("Exit");
		//Creando el objeto de CalculateButtonHandler (manejador de evento)
		CalculateButtonHandler cbHandler = new CalculateButtonHandler();
		//Creando el objeto de ExitButtonHandler (manejador de evento)
		ExitButtonHandler ebHandler = new ExitButtonHandler();
		//Registramos ambos eventos en el manejador de eventos
		calculateB.addActionListener(cbHandler);
		exitB.addActionListener(ebHandler);
		//Aqui se crea la cuadricula y se le asignan un elemento a cada espacio de la misma
		//Tambien se agregan los cuadros de texto
		Container pane = getContentPane();
		pane.setLayout(new GridLayout(5,2));
		pane.add(lenghtL); //Renglon 1, Columna 1
		pane.add(lenghtTF); //Renglon 1, Columna 2
		pane.add(widthL); //Renglon 2, Columna 1
		pane.add(widthTF); //Renglon 2, Columna 2
		pane.add(areaL); //Renglon 3, Columna 1
		pane.add(areaTF); //Renglon 3, Columna 2
		pane.add(perimeterL); //Renglon 4, Columna 1
		pane.add(perimeterTF); //Renglon 4, Columna 2
		//Aqui es donde agregaremos nuestros botones
		pane.add(calculateB); //Renglon 5, Columna 1
		pane.add(exitB); //Renglon 5, Columna 2
		//Aqui se definen las dimensiones de la ventana
		setSize(WIDTH,HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	//Implementacion de la interfaz ActionListener para ambos botones
	private class CalculateButtonHandler implements ActionListener{
	public void actionPerformed(ActionEvent e){
		double width, length, area, perimeter;

		length = Double.parseDouble(lenghtTF.getText());
		width = Double.parseDouble(widthTF.getText());
		area = length * width;
		perimeter = 2 * (length + width);

		areaTF.setText(" "+ area);
		perimeterTF.setText(" "+ perimeter);
		}
	}
	private class ExitButtonHandler implements ActionListener{
		public void actionPerformed(ActionEvent e){
			System.exit(0);
		}
	}
	//Con este metodo main probamos el funcionamiento de la ventana
	public static void main(String[] args) {
		RectangleProgram rectProg = new RectangleProgram();
	}
}