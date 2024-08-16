#include <stdio.h>

int main (int argc, char** argv){
int x = 0;
int y = 0;
int z = 0;
int contador = 0;
int posicion = 0;
x = 0;
y = 1;
contador = 1;
printf ("0 y 1 son los primeros numeros de la serie\n");
printf ("¿Hasta que posicion de la serie desea llegar?:\n");
scanf ("%d", & posicion);

while (contador <= posicion){
z = x + y;
printf ("%d\n", z);
x = y;
y = z;
++contador;
}
return 0;
}
