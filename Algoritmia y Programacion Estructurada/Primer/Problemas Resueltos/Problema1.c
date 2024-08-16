#include <stdio.h>
                                   /*He declarado main con argc y argv, para facilitar la compilacion de todos los problemas*/
int main (int argc, char** argv) { /*argc es el numero de argumentos en el programa y argv es la matriz de argumentos*/
int num1 = 0;
int num2 = 0;

printf ("Porfavor introduzca el primer numero");
scanf ("%d", & num1);
printf ("Porfavor introduzca el segundo numero");
scanf ("%d", & num2);
if (num1 > num2){
   printf ("El mayor es: %d \n", num1);
}
if (num1 < num2){
   printf ("El mayor es: %d \n", num2);
}
return 0;
}
