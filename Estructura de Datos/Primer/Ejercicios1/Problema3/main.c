/*
  AUTOR: BARON HERNANDEZ DIEGO ISMAEL
  DESCRIPCION: Este programa ordena de manera descendente tres numeros dados por el usuario uno a uno.
  COMPILACION: Este programa debe de poder ser compilado y ejecutado en Windows y Linux ya que esta
               programado bajo el standar.
  OBSERVACIONES: Tratar de usar el archivo "makefile" incluido, si falla hacer los comandos escritos
                 en el archivo manualmente en la consola.
  LIBRERIAS: Solo se uso la biblioteca estandar de stdio.h.
*/
#include <stdio.h>
#include "funciones.h"

int
main ()
{
  int num_1 = 0;
  int num_2 = 0;
  int num_3 = 0;
  printf ("\nIntroduce 3 numeros:\n");
  scanf ("%d", &num_1);
  scanf ("%d", &num_2);
  scanf ("%d", &num_3);
  ordenar (num_1, num_2, num_3);
  return 0;
}
