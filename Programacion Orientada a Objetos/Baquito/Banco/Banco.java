public class Banco{
	private Cliente[] clientes;
	private int numClientes;
	//Variable de clase
	public static int indice = 0;
	//Constructor
	public Banco(){
		this.clientes = new Cliente[100];
		this.numClientes = 0;
	}
	//Metodos
	//agregaCliente: Este metodo agrega un cliente a la lista de clientes
	public void agregaCliente(Cliente c){
		clientes[indice] = c;
		indice++;
		numClientes++;
	}
	//obtenerNumClientes: ESte metodo obtiene el numero de clientes totales del banco
	public int obtenerNumClientes(){
		return numClientes;
	}
	//obtenerCliente: Este metodo obtiene un cliente especifico de la lista de clientes
	public Cliente obtenerCliente(int i){
		Cliente aux;
		aux = clientes[i];
		return aux;
	}
	//imprimirClientes: Este metodo despliega en pantalla todos los clientes de la lista
	public void imprimirClientes(){
		int lon = 0;
		Cliente aux;
		lon = clientes.length;
		for (int i=0;i < numClientes; i++) {
			aux = clientes[i];
			System.out.println("No. "+ i +" Nombre: " + aux.obtenerNombre() + " No. Cuenta: " + aux.obtenerNum());	
		}
	}
}