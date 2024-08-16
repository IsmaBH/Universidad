#include <stdio.h>

int main (int argc, char** argv){
int num1 = 0;
int num2 = 0;
int num3 = 0;
printf ("Introduzca el primer numero entero:");
scanf ("%d", & num1);
printf ("Introduzca el segundo numero entero:");
scanf ("%d", & num2);
printf ("Introduzca el tercer numero entero:");
scanf ("%d", & num3);

if (num1 > num2){
   if (num1 > num3){
       printf ("El numero mas alto es: %d\n", num1);
  }
}
if (num2 > num1){
   if (num2 > num3){
      printf ("El numero mas alto es: %d\n", num2);
  }
}
if (num3 > num1){
   if (num3 > num2){
      printf ("El numero mas alto es: %d\n", num3);
  }
}
if (num1 == num2){
   if (num1 == num2){
      printf ("Los numeros son iguales\n");
  }
}
return 0;
}
