/*
 * Clase Libro
 * El objetivo de esta clase es la de obtener los datos mas importantes para el tf-idf
 * de cada libro con respecto a la frase de busqueda
 */

package search;

import java.util.Collections;
import java.util.List;
import java.util.Arrays;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Libro{
	//Atributos
	private File archivo;
	private double[] tf;
	private double[] idf;
	private double pf;
	//Constructor
	public Libro(File file, int TAM){
		this.archivo = file;
		this.tf = new double[TAM];
		this.idf = new double[TAM];
		this.pf = 0.0;
	}
	//Metodos
	public void calculaTF(){}
	public void calculaIDF(){}
	public void calculaPF(){}
	//Metodos get de la clase
	public File getArchivo(){
		return this.archivo;
	}
	public double[] getTf(){
		return this.tf;
	}
	public double[] getIdf(){
		return this.idf;
	}
	public double getPf(){
		return this.pf;
	}
}
