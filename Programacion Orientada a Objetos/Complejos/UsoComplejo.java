public class UsoComplejo{
	public static void main(String[] args) {
		//Creamos tres instancias de la clase complejo
		//Usando los tres constructores
		//Las variables A,B,C son referencias a un complejo
		//El operador new genera la memoria para la instancia de la clase complejo
		
		//Primer constructor sin argumentos
		Complejo A = new Complejo();
		//Segundo constructor
		Complejo B = new Complejo(5,8);
		//Tercer constructor
		Complejo C = new Complejo(B);

		//Uso de los metodos
		//Imprimimos sus valores
		A.imprimir();
		B.imprimir();
		C.imprimir();
		//Ahora sumamos A con B
		A.sumar(B);
		//Comprobamos la suma con el metodo imprimir
		A.imprimir();
		//Ahora sumamos A con B y asignamos el resultado a C
		C.sumar(A,B);
		//Comprobamos
		C.imprimir();
	}//Fin del metodo main
}//Fin de la clase UsoComplejo
//Compilacion con el comando: javac UsoComplejo.java Complejo.java
//Una vez terminada la compilacion ejecutar: java UsoComplejo