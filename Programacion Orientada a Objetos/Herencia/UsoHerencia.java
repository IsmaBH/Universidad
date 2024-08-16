public class UsoHerencia{
	public static void main(String[] args) {
		Empleado e1 = new Empleado("Barack Obama", 3650.45, "00001");
		Gerente g1 = new Gerente("Silvio Berlusconi", 2642.32, "0002", "Espectaculos");
		//El metodo toString de la clase Empleado se invoca de forma implicita
		System.out.println(e1);
		//El metodo toString de la clase Gerente se invoca de forma implicita
		System.out.println(g1);
		g1.contratarPersonal();
		g1.cambiarSalario(3200.46);
		System.out.println(g1);
		//Se anexa el otro posible constructor para la clase Gerente
		//Gerente g2 = new Gerente("Ventas");
	}
}