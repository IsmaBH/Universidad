#include <stdio.h>

int main (int argc, char** argv){
int num1 = 0;
int num2 = 1;
float promedio = 0;
printf ("Introduzca el primer numero:");
scanf ("%d", & num1);
while (num2 != 0){
printf ("Introduzca el siguiente valor:");
scanf ("%d", & num2);
num1 = num1 + num2;
}
promedio = num1 / 2;
printf ("El promedio de los datos es: %f\n", promedio);
return 0;
}
