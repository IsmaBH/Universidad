#include <stdio.h>

int main (int argc, char** argv){
int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int num5 = 0;
int num6 = 0;
int num7 = 0;
int num8 = 0;
int suma = 0;

printf ("Introduzca 8 numeros en el siguiente orden:\n");
printf ("Numero 1:");
scanf ("%d", & num1);
printf ("Numero 2:");
scanf ("%d", & num2);
printf ("Numero 3:");
scanf ("%d", & num3);
printf ("Numero 4:");
scanf ("%d", & num4);
printf ("Numero 5:");
scanf ("%d", & num5);
printf ("Numero 6:");
scanf ("%d", & num6);
printf ("Numero 7:");
scanf ("%d", & num7);
printf ("Numero 8:");
scanf ("%d", & num8);

suma = num1+num2+num3+num4+num5+num6+num7+num8;
printf ("La suma total es: %d\n", suma);
return 0;
}
