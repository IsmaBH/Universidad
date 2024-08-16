#include <stdio.h>

int main (int argc, char** argv){

int num = 0;
printf ("Introduzca un numero entero");
scanf ("%d", & num);
if (num % 2 == 0){
   printf ("Es par\n");
}
else{
   printf ("Es impar\n");
}
return 0;
}

