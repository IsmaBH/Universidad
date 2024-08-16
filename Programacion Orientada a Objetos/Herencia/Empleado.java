public class Empleado{
	protected String nombre;
	protected double salario;
	private String numEmpleado;

	public Empleado(String nom, double sal, String ne){
		nombre = nom;
		salario = sal;
		numEmpleado = ne;
	}

	//El metodo toString es un metodo de la clase object
	//la clase empleado esta redefiniendo este metodo
	public String toString(){
		return "Nombre: "+ nombre + " Salario: "+ salario + " Numero de empleado: "+ numEmpleado;
	}
}