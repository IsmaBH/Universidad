public class Bankito{
	public static void main(String[] args) {
		//Las cuentas auxiliares se crean para luego poder
		//usar los metodos de la clase cuenta sobre los diferentes clientes
		Cuenta ctaAux;
		Cuenta ctaAux2;
		//Creamos al cliente "El Quijote"
		Cliente qx = new Cliente("El Quijote","QX400");
		//Creamos al cliente "Sancho Panza"
		Cliente sp = new Cliente("Sancho Panza","SPANZA");
		//Creamos su cuenta con saldo de 550.45
		qx.establecerCuenta(new Cuenta(550.45));
		//Creamos la cuenta de sp con saldo de 100.35
		sp.establecerCuenta(new Cuenta(100.35));
		//Obtenemos la cuenta del Quijote
		//y asignamos la referencia ctaAux
		ctaAux = qx.obtenerCuenta();
		//Obtenemos la cuenta de Sancho y asignamos la referencia
		ctaAux2 = sp.obtenerCuenta();
		//Ahora depositamos 300.55 pesos a cuenta del Quijote
		ctaAux.depositar(300.55);
		//Realizamos un retiro de la cuenta de Sancho
		ctaAux2.retirar(100.00);
		//Ahora imprimimos toda la informacion del Quijote
		System.out.println("Nombre del cliente:" + qx.obtenerNombre());
		System.out.println("Num cuenta:" + qx.obtenerNum());
		System.out.println("Saldo:" + ctaAux.consultar());
		//Ahora imprimimos la informacion de Sancho
		System.out.println("Nombre del cliente:" + sp.obtenerNombre());
		System.out.println("Num cuenta:" + sp.obtenerNum());
		System.out.println("Saldo:" + ctaAux2.consultar());
	}
}