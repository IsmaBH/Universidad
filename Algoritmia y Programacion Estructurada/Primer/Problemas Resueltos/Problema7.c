#include <stdio.h>
/*Para el Problema 8 se usa este mismo codigo, con excepcion de una variable char extra y un bucle while (char!='S') y un if para controlarlo */
float raiz (int z){/* Doy la explicacion de arriba, debido a que no me dio tiempo de hacer el problema 8*/
float n = 0;
float res = 0;
float i = 0;
n = z;
do{
i= i + 0.1;
res = i * i;
}
while (z >= res);
return i;
}

int main (int argc, char** argv){
int x1 = 0;
int x2 = 0;
int x3 = 0;
int y1 = 0;
int y2 = 0;
int y3 = 0;
int xT1, xT2, xT3 = 0;
int yT1, yT2, yT3 = 0;
int z = 0;
float lado1 = 0;
float lado2 = 0;
float lado3 = 0;
printf ("Introduzca la coordenadas en x1:");
scanf ("%d", & x1);
printf ("Introduzca la coordenadas en x2:");
scanf ("%d", & x2);
printf ("Introduzca la coordenadas en x3:");
scanf ("%d", & x3);
printf ("Introduzca la coordenadas en y1;");
scanf ("%d", & y1);
printf ("Introduzca la coordenadas en y2;");
scanf ("%d", & y2);
printf ("Introduzca la coordenadas en y3;");
scanf ("%d", & y3);
xT1 = x2 - x1;
yT1 = y2 - y1;
z = xT1 + yT1;
lado1 = raiz (z);
printf ("EL primer lado es: %f\n", lado1);
xT2 = x3 - x1;
yT2 = y3 - y1;
z = xT2 + yT2;
lado2 = raiz (z);
printf ("El segundo lado es: %f\n", lado2);
xT3 = x3 - x2;
yT3 = y3 - y2;
z = xT3 + yT3;
lado3 = raiz (z);
printf ("El tercer lado es: %f\n", lado3);
if (lado1==lado2&&lado2==lado3){
   printf ("Es un triangulo: EQUILATERO\n");
}
else if (lado1==lado2||lado1==lado3||lado2==lado3){
   printf ("Es un triangulo: ISOCELES\n");
}
else if (lado1!=lado2&&lado1!=lado3&&lado2!=lado3){
   printf ("Es un triangulo: ESCALENO\n");
}
return 0;
}

