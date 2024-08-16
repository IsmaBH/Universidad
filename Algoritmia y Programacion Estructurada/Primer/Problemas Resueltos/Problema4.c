#include <stdio.h>

int main (int argc, char** argv){
int num = 0;
printf ("Introduzca un numero entero:");
scanf ("%d", & num);
while (num != 0){
      printf ("Introduzca el siguiente numero:");
      scanf ("%d", & num);
}
return 0;
}
