public class Gerente extends Empleado{
	private String area;
	public Gerente(String nom, double sal, String ne, String a){
		//Invocamos al constructor de la super clase con sus 3 argumentos
		super(nom,sal,ne);
		//Continuamos con la construccion del objeto de la clase gerente
		area = a;
	}
	//El metodo toString es un metodo de la clase Object, la clase gerente
	//esta redefiniendo este metodo
	//Usamos la reutilizacion del metodo toString de la super clase
	public String toString(){
		return super.toString()+ " Gerente del area de: " + area;
	}
	public void contratarPersonal(){
		System.out.println("Las contrataciones en el area de: "+ area + "fueron 2");
	}
	//El metodo cambiarSalario ilustra el acceso de la clase Gerente a los atributos
	//protegidos de su clase base
	public void cambiarSalario(double nuevo){
		salario = nuevo;
	}
}