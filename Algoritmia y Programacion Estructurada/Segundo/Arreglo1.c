#include <stdio.h>

int main (int argc, char** argv){
int contador = 0;
int i = 1;
char* cadena;
printf ("El numero de argumentos es: %d\n", argc);
while (contador < argc){
printf ("%s ", *(argv + i));
++contador;
++i;
}
/*printf ("\n");
cadena = *(argv+i);
for (i = 1; contador < *cadena; i++){
printf ("El numero de caracteres para el argumento %d: %s", i, cadena);
++i;
++contador;
}*/
printf ("\n");
return 0;
}
