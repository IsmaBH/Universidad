/*
**Clase que implementa el algoritmo de 
**busqueda por profundidad desde la
**clase abstracta Algoritmo
*/
import java.util.ArrayList;

public class Profundidad extends Algoritmo{
	//Atributos
	private ArbolNario decisiones = new ArbolNario();
	private ArrayList<Integer> prioridad = new ArrayList<Integer>();
	Nodo raiz;
	//Constructor
	public Profundidad(String nombre){
		super(nombre);
	}
	//Implementacion de los metodos abstractos
	public void insertarInicial(Coordenada inicial){
		//Metodo auxiliar que permite colocar la raiz del arbol de decisiones
		raiz = decisiones.insertarRaiz(inicial);
	}
	public void setPrioridad(){
		//Este metodo podra ser cambiado para colocar la prioridad de movimiento deseada
		//Ejemplo: Arriba(38),Derecha(39),Izquierda(37),Abajo(40)
		prioridad.add(38);
		prioridad.add(39);
		prioridad.add(37);
		prioridad.add(40);
	}
	public void verDecisiones(){
		decisiones.recorrer(raiz);
	}
	public int obtenerDireccion(int[][] lab,Personaje p){
		//Metodo que evaluara el laberinto y determinara el siguiente movimiento del agente
		int decision = 0;
		for (int i = 0; i < prioridad.size() ; i++) {
			//Izquierda
			if (prioridad.get(i) == 37 && p.esOcupable(lab[p.getPosicionActual().getY()/40][(p.getPosicionActual().getX()/40)-1]) && !p.esVisitado((p.getPosicionActual().getX()/40)-1,p.getPosicionActual().getY()/40)) {
				decision = 37;
				break;
			}
			//Arriba
			if (prioridad.get(i) == 38 && p.esOcupable(lab[(p.getPosicionActual().getY()/40)-1][p.getPosicionActual().getX()/40]) && !p.esVisitado(p.getPosicionActual().getX()/40,(p.getPosicionActual().getY()/40)-1)) {
				decision = 38;
				break;
			}
			//Derecha
			if (prioridad.get(i) == 39 && p.esOcupable(lab[p.getPosicionActual().getY()/40][(p.getPosicionActual().getX()/40)+1]) && !p.esVisitado((p.getPosicionActual().getX()/40)+1,p.getPosicionActual().getY()/40)) {
				decision = 39;
				break;
			}
			//Abajo
			if (prioridad.get(i) == 40 && p.esOcupable(lab[(p.getPosicionActual().getY()/40)+1][p.getPosicionActual().getX()/40]) && !p.esVisitado(p.getPosicionActual().getX()/40,(p.getPosicionActual().getY()/40)+1)) {
				decision = 40;
				break;
			}
		}
		return decision;
	}
	public void insertarDesiciones(Coordenada actual,int caminos){
		if (raiz.getCoord().getX() == actual.getX() && raiz.getCoord().getY() == actual.getY() && caminos == 1) {
			raiz.setNoHijos(caminos);
		}else{
			if (caminos > 1) {
				if (!decisiones.buscar(raiz,actual,false)) {
					Nodo padre = new Nodo();
					padre = decisiones.buscarPadreProfundidad(raiz);
					decisiones.insertarNodo(raiz,actual,padre.getCoord(),caminos);
					decisiones.actualizarPadre(1,padre.getCoord(),raiz);
				}
			}
		}
	}
	public Coordenada esCallejon(int x,int y){
		Nodo padre = new Nodo();
		Coordenada actual = new Coordenada(x/40,y/40);
		padre = decisiones.buscarPadreProfundidad(raiz);
		decisiones.insertarNodo(raiz,actual,padre.getCoord(),0);
		decisiones.actualizarPadre(1,padre.getCoord(),raiz);
		padre = decisiones.buscarPadreProfundidad(raiz);
		return padre.getCoord();
	}
}