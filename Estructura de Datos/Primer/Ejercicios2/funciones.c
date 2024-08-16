#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int **
Aparta_Matriz (int m, int n)
{
  int i = 0;
  int **matriz;
  matriz = malloc (m * sizeof (int));
  for (i = 0; i < m; i++)
    {
      matriz[i] = malloc (n * sizeof (int));
    }
  return matriz;
}

void
Imprime_Matriz (int **matriz, int m, int n)
{
  int i = 0;
  int j = 0;
  for (i = 0; i < n; i++)
    {
      printf ("\n");
      for (j = 0; j < m; j++)
	{
	  printf ("\t%d", matriz[i][j]);
	}
    }
  return;
}

int
Capturar_Matriz (int **matriz, int m, int n)
{
  int i = 0;
  int j = 0;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
	{
	  printf ("Introduce el elemento[%d] [%d]:", i, j);
	  scanf ("%d", &matriz[i][j]);
	}
    }
  return;
}

int **
Sumar_Matrices (int **matriz1, int **matriz2, int **matriz3, int m, int n)
{
  int i = 0;
  int j = 0;
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
	}
    }
  return matriz3;
}
