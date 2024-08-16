#include <stdio.h>

int main (int argc, char** argv){
int factorial = 0;
printf ("Ingresa el numero a calcular:");
scanf ("%d", & factorial);
int contador = factorial - 1;
int respuesta = factorial;
while (contador >= 1){
      respuesta = respuesta * contador;
      contador--;
  }
printf ("El factorial de %d es: %d\n", factorial, respuesta);
return 0;
}
