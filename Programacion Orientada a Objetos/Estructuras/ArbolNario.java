import java.util.ArrayList;

public class ArbolNario{
	Nodo raiz;
	public ArbolNario(){}
	public Nodo insertarRaiz(String id){
		raiz = new Nodo(id);
		return raiz;
	}
	public void insertarNodo(Nodo nodo,String id,String padre){
		Nodo nuevo = new Nodo(id);
		//Verificamos si el nodo padre es la raiz
		if (nodo.getId().equals(padre)) {
			nodo.aumentarHijo(nuevo);
		}else{
			//Si no buscamos al padre entre los hijos
			for (int i = 0; i < nodo.getNoHijos() ; i++) {
				if (nodo.hijos.get(i).getId().equals(padre)) {
					nodo.hijos.get(i).aumentarHijo(nuevo);
				}else{
					insertarNodo(nodo.hijos.get(i),id,padre);
				}
			}
		}
	}
	public void recorrer(Nodo raiz){
		raiz.verInfo();
		for (int i = 0; i < raiz.getNoHijos() ; i++ ) {
			recorrer(raiz.hijos.get(i));
		}
	}
	public void recorrerHijosRaiz(Nodo raiz){
		for (int i = 0; i<raiz.getNoHijos() ; i++ ) {
			recorrerHijosRaiz(raiz.hijos.get(i));
		}
		raiz.verInfo();
	}
	public boolean buscar(Nodo raiz,String buscar,boolean encontrado){
		if (raiz.getId().equals(buscar)) {
			encontrado = true;
		}
		for (int i = 0; i<raiz.getNoHijos() ; i++) {
			encontrado = buscar(raiz.hijos.get(i),buscar,encontrado);
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
	public int altura(Nodo raiz){
		int mayor = 0;
		int tempo = 0;
		if (raiz == null) {
			return 0;
		}else{
			for (int i = 0; i<raiz.getNoHijos() ; i++) {
				tempo = altura(raiz.hijos.get(i));
				if (tempo > mayor) {
					mayor = tempo;
				}
			}
			return mayor+1;
		}
	}
	public int altura2(Nodo raiz){
		int nivel = 0;
		if (raiz == null) {
			return 0;
		}else{
			for (int i = 0; i < raiz.getNoHijos() ; i++) {
				nivel += altura2(raiz.hijos.get(i));
				if (i == 0) {
					nivel ++;
				}
			}
			return nivel;
		}
	}
	public int altura3(Nodo raiz,int nivel){
		if (raiz == null) {
			return 0;
		}else{
			for (int i = 0; i<raiz.getNoHijos() ; i++) {
				nivel = altura3(raiz.hijos.get(i),nivel);
				if (i == 0) {
					nivel++;
				}
			}
			return nivel;
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
	public int nivelElemento(Nodo raiz,String elemento,int nivel){
		int tempo = 0;
		if (raiz == null) {
			return -1;
		}else if (raiz.getId().equals(elemento)) {
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
	public void borrarNodo(Nodo raiz,String borrar, boolean rama){
		//Para poder borrar primero buscamos que exista el nodo que se pretende borrar
		for (int i = 0; i<raiz.getNoHijos() ; i++ ) {
			//En caso de que se quiera borrar con todo y la rama
			if (raiz.hijos.get(i).getId().equals(borrar)&&raiz.hijos.get(i).getNoHijos() != 0 && rama) {
				raiz.hijos.remove(i);
				raiz.actualizarNoHijos();
				break;
			//En caso contrario se verifica que el nodo no tenga hijos
			}else if (raiz.hijos.get(i).getId().equals(borrar)&&raiz.hijos.get(i).getNoHijos() == 0) {
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
		String id;
		int cantidadHijos;
		ArrayList <Nodo> hijos;
		//Constructores
		public Nodo(String id){
			hijos = new ArrayList<Nodo>();
			this.id = id;
			this.cantidadHijos = 0;
		}
		//Metodos
		public void aumentarHijo(Nodo hijo){
			hijos.add(hijo);
			cantidadHijos = hijos.size();
		}
		public void actualizarNoHijos(){
			cantidadHijos = hijos.size();
		}
		public void verInfo(){
			System.out.println("{ "+id+" }");
		}
		public void verHijos(){
			System.out.println(cantidadHijos);
		}
		public void setid(String id){
			this.id = id;
		}
		public String getId(){
			return id;
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