/**
 * Proyecto No.2
 * Autor: Diego Ismael Barón Hernández
 * Grupo: 4CM14
 */
package com.ipn.dsd.proyecto2;

public class PoligonoReg extends PoligonoIrreg{
        //Atributos de la clase
        public int nVertices;
        public double alfa;

        //Constructor de la clase
        public PoligonoReg(int n){
                super();
                this.nVertices = n;
                this.alfa = 360/nVertices;
        }

        //Metodo obtieneArea: Permite calcular el area del poligono regular
        public double obtieneArea(){
                //Tener en cuenta que lo primero que hay que hacer es calcular el apotema del
                //poligono regular, la formula es Ap = l/2tan(0) y 0 = alfa/2
                double l = Math.sqrt(Math.pow((vertices.get(1).abcisa() - vertices.get(0).abcisa()), 2) + Math.pow((vertices.get(1).ordenada() - vertices.get(0).ordenada()),2));
                double teta = alfa/2;
                double Ap = l/(2*Math.tan(teta));
                //Ahora calculo el area del poligono mediante la formula A = P*Ap/2 donde P = l*nVertices
                //P se calcula asi por la propiedad de los poligonos regulares No. vertices = No. lados
                double Area = ((l*nVertices)*Ap)/2;
                return Area;
        }
}