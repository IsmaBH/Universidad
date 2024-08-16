public class Cuenta{
	private double saldo;
	//Constructor
	public Cuenta(double saldoInicial){
		this.saldo = saldoInicial;
	}
	//Metodos
	//consultar: Solo revisa el saldo actual de la cuenta
	public double consultar(){
		return this.saldo;
	}
	//depositar: Hace la suma total de un deposito
	public void depositar(double monto){
		this.saldo = saldo + monto;
	}
	//retirar: Hace la resta efectuada despues de un retiro
	public void retirar(double monto){
		this.saldo = saldo - monto;
	}
}