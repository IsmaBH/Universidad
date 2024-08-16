public class UsoEmpleado{
	public static void main(String[] args) {
		Empleado e1 = new Empleado("Miguel","1600");
		Empleado e2 = new Empleado("Rosa","1650");
		//Invocacion al metodo de clase de la clase Empleado
		Empleado.reportarEmpleados();
	}
}