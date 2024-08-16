public class Empleado{
	//Variables de instancia
	private String nombre;
	private String rfc;
	//Variable de clase
	public static int contador = 0;
	//Constructor
	public Empleado(String n, String r){
		nombre = n;
		rfc = r;
		contador++;
	}
	//Metodo de clase
	public static void reportarEmpleados(){
		System.out.println("El numero de empleados es: "+ contador);
	}
	//Metodo de instancia
	public void imprime(){
		System.out.println("Nombre = "+nombre+"RFC = "+rfc);
	}
}