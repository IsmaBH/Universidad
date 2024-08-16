import java.util.ArrayList;

public class ArbolNario{
	Nodo raiz;
	public ArbolNario(){
		this.raiz = null;
	}
	public Nodo obtenerRaiz(){
		return this.raiz;
	}
	public Nodo insertarRaiz(Coordenada posicionInicial){
		raiz = new Nodo(posicionInicial);
		return raiz;
	}
	public void insertarNodo(Nodo nodo,Coordenada pos,Coordenada padre,int caminos){
		Nodo nuevo = new Nodo(pos,caminos);
		//Verificamos si el nodo padre es la raiz
		if (nodo.getCoord().getX() == padre.getX() && nodo.getCoord().getY() == padre.getY()) {
			if (caminos == 0) {
				nodo.setOtro("Cerrado");
			}
			nodo.aumentarHijo(nuevo);
		}else{
			//Si no buscamos al padre entre los hijos
			for (int i = 0; i < nodo.getVisitados() ; i++) {
				if (nodo.hijos.get(i).getCoord().getX() == padre.getX() && nodo.hijos.get(i).getCoord().getY() == padre.getY()) {
					if (caminos == 0) {
						nuevo.setOtro("Cerrado");
					}
					nodo.hijos.get(i).aumentarHijo(nuevo);
					//System.out.println("Entre a buscar entre los hijos");
				}else{
					//System.out.println("Entre a buscar al siguiente nivel");
					insertarNodo(nodo.hijos.get(i),pos,padre,caminos);
				}
			}
		}
	}
	public void recorrer(Nodo raiz){
		raiz.verInfo();
		for (int i = 0; i < raiz.getVisitados() ; i++ ) {
			recorrer(raiz.hijos.get(i));
		}
	}
	public void recorrerHijosRaiz(Nodo raiz){
		for (int i = 0; i<raiz.getNoHijos() ; i++ ) {
			recorrerHijosRaiz(raiz.hijos.get(i));
		}
		raiz.verInfo();
	}
	public Nodo buscarPadreProfundidad(Nodo raiz){
		Nodo encontrado = new Nodo();
		for (int i = 0; i<raiz.getVisitados() ; i++ ) {
			encontrado = buscarPadreProfundidad(raiz.hijos.get(i));
		}
		if (raiz.getOtro() == "Abierto" && encontrado.posicion == null) {
			encontrado = raiz;
		}
		return encontrado;
	}
	public void actualizarPadre(int cantidad,Coordenada buscar,Nodo raiz){
		if (raiz.getCoord().getX() == buscar.getX() && raiz.getCoord().getY() == buscar.getY()) {
			raiz.aumentaVisitados(cantidad);
			if (raiz.getVisitados() == raiz.getNoHijos()) {
				raiz.setOtro("Cerrado");
			}
		}else{
			for (int i = 0; i<raiz.getVisitados() ; i++) {
				actualizarPadre(cantidad,buscar,raiz.hijos.get(i));
			}
		}
	}
	public boolean buscar(Nodo raiz,Coordenada buscar,boolean encontrado){
		if (raiz.getCoord().getX() == buscar.getX() && raiz.getCoord().getY() == buscar.getY()) {
			encontrado = true;
		}else{
			//if (raiz.getVisitados() >= 1) {
				for (int i = 0; i < raiz.getVisitados() ; i++) {
					encontrado = buscar(raiz.hijos.get(i),buscar,encontrado);
				}
			//}
		}
		return encontrado;
	}
	public int cantidadNodos(Nodo raiz){
		int mayor = 0;
		if (raiz == null) {
			return 0;
		}else{
			for (int i = 0; i<raiz.getNoHijos() ; i++) {
				mayor += cantidadNodos(raiz.hijos.get(i));
			}
			return mayor+1;
		}
	}
	public int numeroHojas(Nodo raiz){
		int asum = 0;
		if (raiz.getNoHijos() == 0) {
			return 1;
		}else{
			for (int i = 0; i<raiz.getNoHijos() ; i++) {
				asum += numeroHojas(raiz.hijos.get(i));
			}
			return asum;
		}
	}
	public int nivelElemento(Nodo raiz,Coordenada elemento,int nivel){
		int tempo = 0;
		if (raiz == null) {
			return -1;
		}else if (raiz.getCoord().getX() == elemento.getX() && raiz.getCoord().getY() == elemento.getY()) {
			return nivel;
		}else{
			//Se busca en los hijos
			for (int i = 0; i<raiz.getNoHijos() ; i++ ) {
				tempo = nivelElemento(raiz.hijos.get(i),elemento,nivel+1);
				if (tempo != -1) {
					return tempo;
				}
			}
			return -1;
		}
	}
	public void borrarNodo(Nodo raiz,Coordenada borrar, boolean rama){
		//Para poder borrar primero buscamos que exista el nodo que se pretende borrar
		for (int i = 0; i<raiz.getNoHijos() ; i++ ) {
			//En caso de que se quiera borrar con todo y la rama
			if ((raiz.hijos.get(i).getCoord().getX() == borrar.getX() && raiz.hijos.get(i).getCoord().getY() == borrar.getY()) && raiz.hijos.get(i).getNoHijos() != 0 && rama) {
				raiz.hijos.remove(i);
				raiz.actualizarNoHijos();
				break;
			//En caso contrario se verifica que el nodo no tenga hijos
			}else if ((raiz.hijos.get(i).getCoord().getX() == borrar.getX() && raiz.hijos.get(i).getCoord().getY() == borrar.getY())&& raiz.hijos.get(i).getNoHijos() == 0) {
				raiz.hijos.remove(i);
				raiz.actualizarNoHijos();
				break;
			}
			borrarNodo(raiz.hijos.get(i),borrar,rama);
		}
	}
}
class Nodo{
		//Atributos
		Coordenada posicion;
		int cantidadHijos;
		int hijosVisitados;
		String otro;
		ArrayList <Nodo> hijos;
		//Constructores
		public Nodo(Coordenada pos){
			hijos = new ArrayList<Nodo>();
			this.posicion = pos;
			this.cantidadHijos = 0;
			this.hijosVisitados = 0;
			this.otro = "Abierto";
		}
		public Nodo(Coordenada pos,int noHijos){
			hijos = new ArrayList<Nodo>();
			this.posicion = pos;
			this.cantidadHijos = noHijos;
			this.hijosVisitados = 0;
			this.otro = "Abierto";
		}
		public Nodo(){
			posicion = null;
		}
		//Metodos
		public void aumentarHijo(Nodo hijo){
			hijos.add(hijo);
		}
		public void setNoHijos(int numero){
			cantidadHijos = numero;
		}
		public void actualizarNoHijos(){
			cantidadHijos = hijos.size();
		}
		public void verInfo(){
			System.out.println("("+posicion.getX()+","+posicion.getY()+","+otro+","+cantidadHijos+","+hijosVisitados+")");
		}
		public void verHijos(){
			System.out.println(cantidadHijos);
		}
		public int getVisitados(){
			return this.hijosVisitados;
		}
		public void aumentaVisitados(int cantidad){
			hijosVisitados = hijosVisitados + cantidad;
		}
		public void setOtro(String others){
			this.otro = others;
		}
		public String getOtro(){
			return this.otro;
		}
		public void setCoords(Coordenada pos){
			this.posicion = pos;
		}
		public Coordenada getCoord(){
			return this.posicion;
		}
		public int getNoHijos(){
			return cantidadHijos;
		}
		public void restarHijos(){
			this.cantidadHijos--;
		}
		public Nodo retornarNodo(){
			return this;
		}
}