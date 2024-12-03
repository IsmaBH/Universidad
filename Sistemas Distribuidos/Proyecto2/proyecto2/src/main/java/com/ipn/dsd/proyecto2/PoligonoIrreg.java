/**
 * Proyecto No.2
 * Autor: Diego Ismael Barón Hernández
 * Grupo: 4CM14
 */
package com.ipn.dsd.proyecto2;

import java.util.*;
import java.util.List;
import java.util.ArrayList;

public class PoligonoIrreg{
    //Atributos de la clase
    public List<Coordenada> vertices;

    //Constructor de la clase
    public PoligonoIrreg(){
        vertices = new ArrayList<>();
    }
    
    //Metodo get de la clase
    public List<Coordenada> listaVertices(){
        return this.vertices;
    }
    
    //Metodo para buscar una coordenada en la lista
    public boolean contieneElemento(Coordenada c){
        boolean respuesta = false;
        for(int i = 0; i <= vertices.size()-1; i++){
            if(vertices.get(i).abcisa() == c.abcisa() && vertices.get(i).ordenada() == c.ordenada()){
                respuesta = true;
                break;
            }
        }
        return respuesta;
    }

    //Metodo para agregar vertices: Permite añadir la coordenada de un vertice del Poligono
    public void anadeVertice(Coordenada vertice){
        vertices.add(vertice);
    }

    //Metodo de ordenamiento de vertices: Permite ordenar los vertices dde acuerdo a su distancia con el origen
    public void ordenaVertices(){
            Collections.sort(vertices, new SortDistance());
            System.out.println(vertices);
    }

    @Override
    public String toString(){
        String cadena = "Los vertices del poligono son : ";
        for (Coordenada v : vertices) {
            cadena +=  v + " ";
        }
        return cadena;
    }
}