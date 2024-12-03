/*
 * Clase Busqueda
 * El objetivo de la clase es almacenar los elementos basicos para llevar acabo
 * una busqueda de mineria de texto en libros con formato texto, esto mediante
 * la aplicacion del metodo "tf-idf".
 * Las principales caracteristicas que tendra (atributios) seran:
 *  -Las puntuaciones finales de cada libro
 *  -La frase en cuestion que se quiere buscar
 *  -El numero total de libros en los que se buscara
 *  -El numero de libros en los que aparece al menos una vez cada una de las palabras de la frase
 * Por ultimo como metodos disponibles estara:
 *  -Ordenamiento de los puntajes de los libros de mayor a menor
 *  -Metodos set de los atributos
 */

package search;

import java.util.Collections;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import search.Libro;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.text.ParseException;

public class Busqueda{
	//Atributos de la clase
	private List<Libro> libros;
	private String[] frase;
	private int noLibros;
	private int[] nt;
	//Constructor
	public Busqueda(String p[]){
		this.libros = new ArrayList<Libro>();
		this.frase = p;
		this.noLibros = 0;
		this.nt = new int[p.length];
	}
	//Metodos
	//public void ordenaLibros(){}
	public void setLibros(File folder){
		for(File file : folder.listFiles()){
			if(!file.isDirectory()){
				Libro l1 = new Libro(file,this.frase.length);
				this.libros.add(l1);
				//System.out.println(file.getName());
			}else{
				setLibros(file);
			}
		}
	}
	public void setNoLibros(){
		this.noLibros = this.libros.size();
	}
	public void setNtFrase(){
		//Este metodo es especial porque prepara el dato nt de cada palabra de la frase para su posterior uso
		//por el algoritmo del tf-idf, esto lo hace buscando en cada uno de los libros de la lista cada 
		//palabra de la frase pero basta con que aparezca una sola vez para determinar que el libro la contiene
		//Por consiguiente se itera sobre el array de palabras de la frase
		String linea;
		Scanner entrada = null;
		for(int i = 0; i < frase.length; i++){
			String palabra = frase[i];
			int contador = 0;
			//El segundo for servira para iterar sobre la lista de libros
			for(int j = 0; j < libros.size(); j++){
				File f = libros.get(j).getArchivo();
				//Aqui se hace la busqueda de la palabra
				try{
					entrada = new Scanner(f);
					while (entrada.hasNext()) {
						linea = entrada.nextLine();
						if (linea.contains(palabra)) {
							contador += 1;
							break;
						}
					}
				}catch(NullPointerException e){
					System.out.println(e.toString() + "No ha seleccionado ningún archivo");
				}catch(Exception e){
					System.out.println(e.toString());
				}finally {
					entrada.close();
				}
				nt[i] = contador;
			}
		}
	}
	public List<Libro> getLibros(){
		return this.libros;
	}
	public String[] getFrase(){
		return this.frase;
	}
	public int getNoLibros(){
		return this.noLibros;
	}
	public int[] getNt(){
		return this.nt;
	}
}
