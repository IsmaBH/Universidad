import java.util.*;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Random;

public class Proyecto2
{
  public static void main (String[]args)
  {
    //Lo primero sera pedir al usuario el numero de poligonos que se crearan
    System.out.println ("Introduzca el numero de poligonos a crear: ");
    Scanner entrada = new Scanner (System.in);
    int n = entrada.nextInt ();
    Random rnd = new Random();
    //Lo siguiente sera preparar la lista de poligonos
    List <PoligonoReg> poligonos = new ArrayList <PoligonoReg> ();
    //Generamos cada uno de los poligonos
    for (int i = 1; i <= n; i++)
      {
	//Primero se decide el numero de vertices del poligono (El minimo es 3)
	int vertices = (int) (Math.random () * ((8 - 3) + 1) + 3);
	System.out.println("Poligono "+i+" vertices escogidos: "+vertices);
	//Ahora generamos los vertices indicados con algunas restricciones
	//Restriccion 1: La distancia de cada vertice debe ser siempre igual
	//Restriccion 2: Los vertices no pueden repetirse
	PoligonoReg poligono = new PoligonoReg (vertices);
	double xAleatoria = rnd.nextDouble()*((500 - 300) + 1) + 300;
	double x = (double)(Math.round(xAleatoria*10.0)/10.0);
	double yAleatoria = rnd.nextDouble()*((400 - 200) + 1) + 200;
	double y = (double)(Math.round(yAleatoria*10.0)/10.0);
	Coordenada inicial = new Coordenada (x, y);
	  poligono.anadeVertice (inicial);
	for (int j = 2; j <= vertices; j++)
	  {
	    //Aqui se generan los vertices restantes con respecto al primero
	    xAleatoria = rnd.nextDouble() * ((500 - 300) + 1) + 300;
	    yAleatoria = rnd.nextDouble() * ((400 - 200) + 1) + 200;
	    x = (double)(Math.round(xAleatoria*10.0)/10.0);
	    y = (double)(Math.round(yAleatoria*10.0)/10.0);
	    if (inicial.abcisa () != x && inicial.ordenada () != y)
	      {
		Coordenada c = new Coordenada (x, y);
		if (c.distancia() == inicial.distancia())
		  {
		    poligono.anadeVertice(c);
		  }
		else
		  {
		    j--;
		  }
	      }
	    else
	      {
		j--;
	      }
	  }
	poligonos.add(poligono);
      }
    //Ahora imprimimos los poligonos creados
    for (int i = 0; i < poligonos.size (); i++)
      {
	System.out.println ("El area del Poligono "+i+" es: "+poligonos.get(i).obtieneArea());
      }
    //Hacemos la organizacion de los poligonos deacuerdo a su area
    Collections.sort(poligonos, new SortArea());
    //Impresion de la lista ordenada
    System.out.println("Ordenamiento de poligonos por area ... ");
    for(int i = 0; i < poligonos.size(); i++){
	    System.out.println("El area del Poligono "+i+" es: "+poligonos.get(i).obtieneArea());
    }
  }
}
