/*
 * Proyecto No.2
 * Autor: Diego Ismael Barón Hernández
 * Grupo: 4CM14
 */

package com.ipn.dsd.proyecto2;
import java.util.*;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;
import java.awt.*;

public class Proyecto2 extends JFrame{
  public static List <Polygon> pol = new ArrayList <> ();;
  public static void main (String[]args){
    //Lo primero sera pedir al usuario el numero de poligonos que se crearan
    System.out.println ("Introduzca el numero de poligonos a crear: ");
    Scanner entrada = new Scanner (System.in);
    int n = entrada.nextInt ();
    Random rnd = new Random();
    //Lo siguiente sera preparar la lista de poligonos
    List <PoligonoReg> poligonos = new ArrayList <> ();
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
        double alfaRad = (poligono.alfa*Math.PI)/180;
        double m = Math.tan(alfaRad);
	double xAleatoria = rnd.nextDouble()*((500 - 300) + 1) + 300;
	double x = (double)(Math.round(xAleatoria*10.0)/10.0);
	double yAleatoria = rnd.nextDouble()*((400 - 200) + 1) + 200;
	double y = (double)(Math.round(yAleatoria*10.0)/10.0);
	Coordenada inicial = new Coordenada (x, y);
	poligono.anadeVertice (inicial);
        System.out.println("Coordenada inicial: "+inicial);
        xAleatoria = rnd.nextDouble()*((500 - 300) + 1) + 300;
	x = (double)(Math.round(xAleatoria*10.0)/10.0);
        yAleatoria = m*(x - inicial.abcisa()) + inicial.ordenada();
        y = (double)(Math.round(yAleatoria*10.0)/10.0);
        Coordenada siguiente = new Coordenada(x,y);
        poligono.anadeVertice(siguiente);
        System.out.println("Coordenada complementaria: "+siguiente);
        double Aux1 = Math.sqrt(Math.pow((poligono.listaVertices().get(1).abcisa() - poligono.listaVertices().get(0).abcisa()), 2) + Math.pow((poligono.listaVertices().get(1).ordenada() - poligono.listaVertices().get(0).ordenada()),2));
        double l = (double)(Math.round(Aux1*10.0)/10.0);
	for (int j = 3; j <= vertices; j++)
	  {
	    //Aqui se generan los vertices restantes con respecto al primero
            alfaRad = ((poligono.alfa*(j-1))*Math.PI)/180;
            m = Math.tan(alfaRad);
            xAleatoria = rnd.nextDouble()*((500 - 300) + 1) + 300;
            x = (double)(Math.round(xAleatoria*10.0)/10.0);
            yAleatoria = m*(x - poligono.listaVertices().get(j-2).abcisa()) + poligono.listaVertices().get(j-2).ordenada();
            y = (double)(Math.round(yAleatoria*10.0)/10.0);
            Coordenada c = new Coordenada(x,y);
            if(poligono.contieneElemento(c) == false){
                //Si no contiene al elemento, se verifica si tiene la misma distancia l con el punto anterior
                double Aux2 = Math.sqrt(Math.pow((x - poligono.listaVertices().get(j-2).abcisa()), 2) + Math.pow((y - poligono.listaVertices().get(j-2).ordenada()),2));
                double lAux = (double)(Math.round(Aux2*10.0)/10.0);
                double Aux3 = lAux - l;
                double diferencia = (double)(Math.round(Aux3*10.0)/10.0);
                if(diferencia <= 0.4 && diferencia >= -0.4){
                    //Si la distancia entre los dos puntos es la misma entonces es un punto valido
                    System.out.println("Coordenada elegida: "+c);
                    poligono.anadeVertice(c);
                }else{
                    //double dif = lAux-l;
                    //System.out.println("Diferencia: "+dif);
                    j--;
                }
            }else{
                j--;
            }
	  }
	poligonos.add(poligono);
      }
    //Creamos una lista de la clase Polygon para su posterior uso en la clase panel
    for(int i = 0; i < poligonos.size(); i++){
        Polygon a = new Polygon();
        for(int j = 0; j < poligonos.get(i).listaVertices().size(); j++){
            a.addPoint((int)poligonos.get(i).listaVertices().get(j).abcisa(),(int)poligonos.get(i).listaVertices().get(j).ordenada());
        }
        pol.add(a);
    }
    
    //Ahora hacemos la primera llamada a la interfaz grafica
    Proyecto2 gui = new Proyecto2();
    gui.setVisible(true);
    //Hacemos la organizacion de los poligonos deacuerdo a su area
    Collections.sort(poligonos, new SortArea());
  }
  public Proyecto2(){
      setSize(800,600);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Panel p = new Panel();
      add(p);
  }
  private class Panel extends JPanel{
      @Override
      public void paintComponent(Graphics g){
          g.setColor(Color.blue);
          for(int i = 0; i < pol.size(); i++){
              g.drawPolygon(pol.get(i));
          }
      }
  }
}