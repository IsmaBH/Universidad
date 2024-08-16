/* 
  AUTOR: BARON HERNANDEZ DIEGO ISMAEL
  DESCRIPCION: Este programa imprime la serie fibonacci hasta la posicion que indique el usuario, con un intervalo de 1 segundo por cada
               resultado, el tiempo fue debido a la incompatibilidad de algunas librerias con el entorno de Linux asi que fue necesario
               hacer el retraso manualmente.
  COMPILACION: Debido a la programacion manual del retraso fue necesario usar una libreria fuera del estandar por lo que se a tenido
               que compilar en el standar de c99 usando el comando "gcc -std=c99 main.c" en el entorno de Linux, aun por comprobar en
               Windows.
  OBSERVACIONES: Fuera de lo anterior mencionado con la incompatibilidad de librerias no hay ninguna otra observacion.
  LIBRERIAS: La principal del estandar "stdio.h" y la libreria para hacer el contador de retraso "time.h".
*/

#include <stdio.h>
#include <time.h>

void
delay (int secs)
{
  for (int i = (time (NULL) + secs); time (NULL) != i; time (NULL));
}

int
main ()
{
  int x = 0;
  int y = 0;
  int z = 0;
  int contador = 0;
  int posicion = 0;
  x = 0;
  y = 1;
  contador = 1;
  printf ("0 y 1 son los primeros numeros de la serie\n");
  printf ("Posicion:\n");
  scanf ("%d", &posicion);

  while (contador <= posicion)
    {
      z = x + y;
      printf ("%d\n", z);
      x = y;
      y = z;
      ++contador;
      delay (1);
    }
  return 0;
}
