public class UsoBanco{
	public static void main(String[] args) {
		//Creamos el banco "Popular"
		Banco popular = new Banco();
		//Creamos algunos clientes para el banco
		Cliente od = new Cliente("Odette","QX401");
		Cliente is = new Cliente("Ismael","QX402");
		Cliente cy = new Cliente("Cynthia","QX403");
		Cliente sc = new Cliente("Oscar","QX404");
		Cliente re = new Cliente("Reyna","QX405");
		//Ahora iniciamos la apertura de las cuentas
		od.establecerCuenta(new Cuenta(120.23));
		is.establecerCuenta(new Cuenta(220.23));
		cy.establecerCuenta(new Cuenta(330.23));
		sc.establecerCuenta(new Cuenta(20.23));
		re.establecerCuenta(new Cuenta(100.23));
		//Los agregamos a la lista de clientes del banco
		popular.agregaCliente(od);
		popular.agregaCliente(is);
		popular.agregaCliente(cy);
		popular.agregaCliente(sc);
		popular.agregaCliente(re);
		//Imprimimos la informacion hasta el momento de los clientes
		popular.imprimirClientes();
	}
}