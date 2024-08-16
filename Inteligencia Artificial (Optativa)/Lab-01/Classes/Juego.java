/*
** Clase que implenta la union de las
** Clases Laberinto y Personaje
*/

import java.awt.Graphics;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.util.Scanner;

public class Juego extends JPanel{
	//Atributos de la clase
	Laberinto laberinto = new Laberinto();
	Personaje personaje = new Personaje();
	//Constructor de la clase
	public Juego(){
		addKeyListener(new KeyListener(){
			@Override
			public void keyTyped(KeyEvent e){}
			@Override
			public void keyPressed(KeyEvent e){
				personaje.teclaPresionada(e);
			}
			@Override
			public void keyReleased(KeyEvent e){}
		});
		setFocusable(true);
	}
	//Metodos de la clase
	@Override
	public void paint(Graphics grafico){
		//Empieza el metodo que nos permitira dibujar el laberinto
		laberinto.paint(grafico,personaje);
		personaje.paint(grafico);
	}
	public void setPersonaje(String opcion){
		switch(opcion){
			case "1":
				personaje.setRaza(opcion);
				break;
			case "2":
				personaje.setRaza(opcion);
				break;
			case "3":
				personaje.setRaza(opcion);
				break;
			default:
				System.out.println("No haz escogido ningun tipo,intenta nuevamente");
				System.exit(0);
		}
	}
	public static void main(String[] args){
		String personajeSeleccionado;
		System.out.println("Personajes disponibles: 1.- Humano, 2.- Mono, 3.- Pulpo");
		Scanner opcion = new Scanner(System.in);
		personajeSeleccionado = opcion.nextLine();
		JFrame miventana = new JFrame("Mi laberinto");
		Juego game = new Juego();
		game.setPersonaje(personajeSeleccionado);
		miventana.add(game);
		miventana.setSize(920,720);
		miventana.setLocation(300,200);
		miventana.setVisible(true);
		miventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		while(true){
			try{
				Thread.sleep(10);
				miventana.repaint();
			}catch(InterruptedException ex){
				System.out.println("Ocurrio un error");
			}
		}
	}
}
