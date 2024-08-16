#include <stdio.h>
#include "cabecera.h"
int main (){
int Nmenu = 0;
if (Nmenu = 0){
char* uni1 = "Longitud";
char* uni2 = "Masa";
char* uni3 = "Temperatura";
char* uni4 = "Tiempo";
int select = 0;
select = menu(&uni1,&uni2,&uni3,&uni4);
printf ("¿Que desea convertir?\n");
scanf ("%d", &select);
printf ("La opcion seleccionada es %d \n", select);
}
return 0;
}
