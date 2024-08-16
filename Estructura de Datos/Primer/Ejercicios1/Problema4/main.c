/*
  AUTOR: BARON HERNANDEZ DIEGO ISMAEL
  DESCRIPCION: Este programa calcula el cubo de n cantidad de numeros dados por el usuario.
  COMPILACION: La compilacion se llevo acabo desde Ubuntu 14.04 (Linux), aun por probar en Windows.
  OBSERVACIONES: El programa trabaja con banderas y por la funcion de "strtok" es necesario introducir
                 un 0 antes de los valores a calcular, usar el archivo "makefile" para generar el ejecutable
                 de no ser posible, hacer manualmente los comandos en la consola.
  LIBRERIAS: Se han usado librerias complementarias a stdio.h como: getopt.h, string.h .
*/
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "funciones.h"

int
main (int argc, char **argv)
{
  int i = 0;
  int x = 0;
  int At = 0;
  char *ptrA;
  char s2[2] = ",";
  int A[200];
  int c = 0;
  int longitud = 0;
  char *aname = "VALOR A";
  extern char *optarg;
  while ((c = getopt (argc, argv, "a:")) != -1)
    {
      switch (c)
	{
	case 'a':
	  aname = optarg;
	  break;
	case '?':
	  printf ("Utilice la bandera correcta");
	  break;
	}
    }
  ptrA = strtok (aname, s2);
  while ((ptrA = strtok (NULL, s2)) != NULL)
    {
      x = atoi (ptrA);
      A[i] = x;
      i++;
      At++;
    }
  printf ("\n");
  for (i = 0; i < At; i++)
    {
      cubo (A[i]);
    }
  printf ("\n");
  return 0;
}
