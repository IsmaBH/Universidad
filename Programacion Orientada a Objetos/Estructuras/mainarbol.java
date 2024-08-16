public class mainarbol{
	public static void main(String[] args) {
	ArbolNario ObjArbol = new ArbolNario();
	Nodo raiz = ObjArbol.insertarRaiz("0");

	ObjArbol.insertarNodo(raiz,"1","0");
	ObjArbol.insertarNodo(raiz,"2","0");
	ObjArbol.insertarNodo(raiz,"3","0");
	ObjArbol.insertarNodo(raiz,"4","0");
	ObjArbol.insertarNodo(raiz,"1.1","1");
	ObjArbol.insertarNodo(raiz,"2.1","2");
	ObjArbol.insertarNodo(raiz,"3.1","3");
	ObjArbol.insertarNodo(raiz,"3.1.1","3.1");
	ObjArbol.insertarNodo(raiz,"3.1.1.4","3.1.1");
	ObjArbol.insertarNodo(raiz,"1.1.1","1.1");
	ObjArbol.insertarNodo(raiz,"1.1.1.2","1.1.1");
	ObjArbol.recorrer(raiz);
	System.out.println("Buscar "+ObjArbol.buscar(raiz,"2",false));
	System.out.println("Cantidad: "+ObjArbol.cantidadNodos(raiz));
	System.out.println("Altura: "+ObjArbol.altura(raiz));
	System.out.println("Altura2: "+ObjArbol.altura2(raiz));
	System.out.println("Altura3: "+ObjArbol.altura3(raiz,0));
	System.out.println("Hojas: "+ObjArbol.numeroHojas(raiz));
	System.out.println("Nivel Elemento: "+ObjArbol.nivelElemento(raiz,"1.",0));
	System.out.println("---------------------------------------------------------");
	ObjArbol.borrarNodo(raiz,"4",true);
	ObjArbol.recorrer(raiz);
	System.out.println("------------------------------------------------------");
	ObjArbol.recorrerHijosRaiz(raiz);
	}
}