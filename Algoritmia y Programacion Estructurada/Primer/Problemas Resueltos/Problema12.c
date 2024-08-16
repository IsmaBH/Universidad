#include <stdio.h>
/* Este programa muestra las tablas de multiplicar deacuerdo a la tabla en especifico que quiera ver el usuario*/
int main (int argc, char** argv){
int tabla = 0;
int multiplicando = 0;
int resultado = 0;
printf ("Introduzca el numero de la tabla que desee ver:");
scanf ("%d", & tabla);
multiplicando = 1;
while (multiplicando <= 10){
resultado = tabla * multiplicando;
printf ("%d x %d = %d\n", tabla, multiplicando, resultado);
++multiplicando;
}
return 0;
}
