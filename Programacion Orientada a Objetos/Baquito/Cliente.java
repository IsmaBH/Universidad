public class Cliente{
	//Atributo con acceso privado
	private String nombre;
	private Cuenta cuenta;
	private String numCta;
	//Constructor (inicializa objetos de la clase cliente)
	public Cliente(String nombre, String numCta){
		this.nombre = nombre;
		this.numCta = numCta;
	}
	//Metodos
	//obtenerNombre: devuelve el nombre
	public String obtenerNombre(){
		return nombre;
	}
	//obtenerCuenta: devuelve el objeto de la clase Cuenta
	public Cuenta obtenerCuenta(){
		return cuenta;
	}
	//establecerCuenta: establece el objeto de la clase Cuenta
	public void establecerCuenta(Cuenta cta){
		cuenta = cta;
	}
	//obtenerNum: devuelve el numero de la cuenta
	public String obtenerNum(){
		return numCta;
	}
}