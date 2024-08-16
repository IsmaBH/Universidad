#include <stdio.h>

int main (int argc, char** argv){
int num1 = 0;
int num2 = 1;
printf ("Introduzca el primer numero:");
scanf ("%d", & num1);
do{
     printf ("Introduzca el siguiente valor");
     scanf ("%d", & num2);
     if (num1 < num2){
        num1 = num2;
     }
}
while (num2 != 0);
printf ("El numero mas alto es; %d\n", num1);
return 0;
}
