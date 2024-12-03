/**
 * Proyecto No.2
 * Autor: Diego Ismael Barón Hernández
 * Grupo: 4CM14
 */
package com.ipn.dsd.proyecto2;

import java.util.*;

public class Coordenada{

    private double x, y, d;

    public Coordenada(double x, double y){
        this.x = x;
        this.y = y;
        this.d = (double)(Math.round(Math.sqrt(Math.pow(x-400,2) + Math.pow(y-300,2))*100.0)/100.0);
    }

    public double abcisa(){
        return x;
    }

    public double ordenada(){
        return y;
    }

    public double distancia(){
            return d;
    }

    @Override
    public String toString(){
        return "[" + x + "," + y + "]";
    }
}