/*
  AUTOR: BARON HERNANDEZ DIEGO ISMAEL
  DESCRIPCION: Este programa recive dos matrices, las suma y devuelve una tercera como resultado.
  COMPILACION: El programa esta en el estandar por lo que es ejecutable tanto en windows y linux, usar el makefile incluido
               y usarlo en una carpeta unicamente con los archivos del programa.
  OBSERVACIONES: Desconosco el motivo pero el programa solo acepta matrices de 4x4 como maximo, al ingresar de 5 en adelante
                 el programa deja de funcionar y salta un error de "violacion de segmento".
  LIBRERIAS: Solo se utilizo la libreria estandar "stdio.h" y su extension "stdlib.h" para el correcto funcionamiento.
  
*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int
main (void)
{
  int m = 0;
  int n = 0;
  int i = 0;
  int j = 0;
  int **matriz1;
  int **matriz2;
  int **matriz3;
  printf ("Introduce el numero de filas y columnas para la matriz 1\n");
  scanf ("%d %d", &m, &n);
  matriz1 = Aparta_Matriz (m, n);	//Aparta el espacio en memoria para la matriz 
  printf ("Se aparto la memoria con exito...\n");	//Esta linea es meramente estetica
  Capturar_Matriz (matriz1, m, n);
  printf ("\n");
  printf ("Introduce el numero de filas y columnas para la matriz 2\n");
  scanf ("%d %d", &i, &j);
  matriz2 = Aparta_Matriz (i, j);	//Aparta el espacio en la memoria para la matriz
  printf ("Se aparto la memoria con exito...\n");	//Esta linea es meramente estetica
  Capturar_Matriz (matriz2, i, j);
  Imprime_Matriz (matriz1, m, n);
  printf ("\n");
  Imprime_Matriz (matriz2, i, j);
  printf ("\n");
  printf ("La suma de las matrices es\n");	//Esta linea es meramente estetica
  printf ("..........................\n");	//Esta line es meramente estetica
  matriz3 = Aparta_Matriz (m, n);	//Aparta el espacio para la matriz resultante
  matriz3 = Sumar_Matrices (matriz1, matriz2, matriz3, m, n);
  Imprime_Matriz (matriz3, n, m);
  printf ("\n");
  return 0;
}
