#include <stdio.h>
#include <getopt.h>
#include "funciones.h"

void
cubo (A)
{
  int resultado = 0;
  resultado = A * A * A;
  printf ("%d,", resultado);
}
