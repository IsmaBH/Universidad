#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
void Imprimir_cajas (int cajas);
Descripcion: Procedimiento para imprimir, por medio de la salida estándar, las cajas deseadas por el usuario
Recibe: int cajas (el número de cajas requeridas por el usuario)
Devuelve: Imprime, por medio de la salida estándar, int cajas (el número de cajas requeridas por el usuario) distribuidas en el marco dibujado
Observaciones: Es muy larga la funcion.
*/
void
Imprimir_cajas (int cajas)	// La funcion que imprime las cajas en pantalla por medio de la funcion move() y printw(), recibe el numero de cajas abiertas para saber cuantas dibujar, contiene el caso de 1 cajas hasta 10 cajas.
{
  int i = 0;
  int x = 7;
  int f = 0;
  char c;
  if (cajas == 1)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 55);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 56);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 55);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 56);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 55);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 56);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
  if (cajas == 2)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 45);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 46);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 45);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 46);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 45);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 46);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 65);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 66);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 65);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 66);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 65);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 66);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
  if (cajas == 3)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 35);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 36);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 35);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 36);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 35);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 36);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 55);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 56);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 55);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 56);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 55);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 56);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Tercer caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 75);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 76);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 75);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 76);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 75);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 76);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
  if (cajas == 4)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 25);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 26);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 25);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 26);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 25);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 26);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 45);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 46);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 45);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 46);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 45);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 46);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Tercer caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 65);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 66);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 65);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 66);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 65);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 66);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Cuarta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 85);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 86);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 85);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 86);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 85);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 86);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
  if (cajas == 5)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 15);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 16);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 15);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 16);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 15);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 16);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 35);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 36);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 35);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 36);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 35);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 36);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Tercer caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 55);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 56);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 55);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 56);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 55);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 56);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Cuarta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 75);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 76);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 75);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 76);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 75);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 76);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Quinta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 95);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 96);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 95);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 96);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 95);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 96);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda.
    }
  if (cajas == 6)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 10);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 11);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 10);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 11);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 10);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 11);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 30);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 31);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 30);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 31);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 30);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 31);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Tercer caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 50);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 51);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 50);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 51);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 50);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 51);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Cuarta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 70);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 71);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 70);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 71);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 70);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 71);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Quinta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 90);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 91);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 90);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 91);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 90);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 91);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Sexta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 110);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 111);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 110);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 111);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 110);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 111);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
  if (cajas == 7)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 9);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 10);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 9);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 10);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 9);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 10);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 24);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 25);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 24);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 25);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 24);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 25);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Tercer caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 39);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 40);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 39);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 40);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 39);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 40);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Cuarta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 54);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 55);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 54);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 55);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 54);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 55);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Quinta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 69);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 70);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 69);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 70);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 69);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 70);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Sexta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 84);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 85);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 84);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 85);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 84);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 85);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Septima caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 99);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 100);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 99);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 100);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 99);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 100);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
  if (cajas == 8)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 9);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 10);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 9);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 10);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 9);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 10);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 24);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 25);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 24);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 25);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 24);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 25);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Tercer caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 39);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 40);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 39);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 40);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 39);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 40);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Cuarta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 54);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 55);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 54);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 55);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 54);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 55);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Quinta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 69);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 70);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 69);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 70);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 69);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 70);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Sexta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 84);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 85);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 84);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 85);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 84);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 85);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Septima caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 99);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 100);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 99);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 100);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 99);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 100);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Octava caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 114);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 115);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 114);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 115);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 114);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 115);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
  if (cajas == 9)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 7);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 8);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 7);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 8);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 7);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 8);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 22);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 23);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 22);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 23);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 22);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 23);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Tercer caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 37);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 38);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 37);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 38);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 37);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 38);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Cuarta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 52);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 53);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 52);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 53);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 52);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 53);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Quinta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 67);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 68);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 67);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 68);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 67);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 68);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Sexta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 82);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 83);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 82);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 83);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 82);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 83);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Septima caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 97);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 98);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 97);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 98);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 97);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 98);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Octava caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 112);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 113);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 112);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 113);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 112);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 113);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Novena caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 127);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 128);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 127);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 128);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 127);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 128);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
  if (cajas == 10)
    {
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 7);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 8);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 7);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 8);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 7);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 8);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.

      //Segunda caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 20);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 21);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 20);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 21);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 20);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 21);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Tercer caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 33);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 34);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 33);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 34);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 33);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 34);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Cuarta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 46);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 47);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 46);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 47);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 46);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 47);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Quinta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 59);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 60);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 59);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 60);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 59);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 60);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Sexta caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 72);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 73);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 72);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 73);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 72);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 73);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Septima caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 85);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 86);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 85);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 86);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 85);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 86);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Octava caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 98);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 99);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 98);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 99);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 98);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 99);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Novena caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 111);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 112);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 111);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 112);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 111);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 112);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda

      //Decima caja
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (5, 124);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (5, 125);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
      c = 124;
      move (6, 124);
      printw ("%c", c);
      //linea vertical derecha
      move (6, 125);
      printw ("%c", c);
      c = 61;			//caracter ascci horizontal
      //linea horizontal superior
      move (7, 124);		//Aqui estamos moviendo el cursor para a linea 1 columna i.
      printw ("%c", c);		//Imprimimos un texto en la posición establecida.
      //linea horizontal inferior
      move (7, 125);		//Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw ("%c", c);		//Imprimimos un  texto en la posición establecida.
      //linea vertical izquierda
    }
}
