public class Complejo{
	private int re; //PArte real, Solo la clase tiene acceso
	private int im; //PArte imaginaria, solo la clase tiene acceso
	//Primer constructor
	Complejo(){
		re = 1;
		im = 1;
	}
	//Segundo constructor
	Complejo(int r, int i){
		re = r;
		im = i;
	}
	//Tercer constructor
	Complejo(Complejo var){
		re = var.re; //var.re es la parte real de otro numero real dado
		im = var.im; //var.im es la parte imaginaria de otro numero imaginario dado
	}
	//Definicion de los metodos de suma
	void sumar(Complejo var){
		re = re + var.re;
		im = im + var.im;
	}
	void sumar(Complejo var1, Complejo var2){
		re = var1.re + var2.re;
		im = var1.im + var2.im;
	}
	//Definicion de metodos resta
	void restar(Complejo var){
		re = re - var.re;
		im = im - var.im;
	}
	void restar(Complejo var1, Complejo var2){
		re = var1.re - var2.re;
		im = var1.im - var2.im;
	}
	//Definicion del metodo imprimir que despliega
	//los valores de la parte real e imaginaria de un objeto
	void imprimir(){
		System.out.println("re= "+re+"im= "+im);
	}
}//Fin de la clase complejo