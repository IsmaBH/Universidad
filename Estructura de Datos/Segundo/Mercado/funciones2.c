#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "TADColaEst.h"

/*
char* titulo (char* nombre);
Descripcion: Procedimiento para capturar, por medio de la entrada estándar, el nombre del supermercado
Recibe: char *nombre (Referencia a la cadena del nombre del supermercado)
Devuelve: char *nombre (Referencia a la cadena del nombre del supermercado)
Observaciones: De manera adicional se usa fgets para poder recibir la cadena de caracteres con o sin espacios.
*/
char *
titulo (char *nombre)
{
  printf ("\n\n Introducir nombre del supermercado : ");
  fgets (nombre, 100, stdin);
  return nombre;
}

/*
int disponibles (int cajas);
Descripcion: Procedimiento para capturar, por medio de la entrada estándar, el numero de cajas requeridas por el usuario
Recibe: int cajas (el número de cajas requeridas por el usuario)
Devuelve: int cajas (el número de cajas requeridas por el usuario)
Observaciones: 
*/
int
disponibles (int cajas)
{
  printf ("\n\n Introducir número de cajas abiertas : ");
  scanf ("%d", &cajas);
  return cajas;
}

/*
void filas (int cajas, int *tiempo_cajas);
Descripcion: Procedimiento para capturar el tiempo de atencion que tendrá cada una de las cajas abiertas.
Recibe: int cajas (el número de cajas requeridas por el usuario), int *tiempo_cajas (Referencia al arreglo de los tiempos de las cajas)
Devuelve: 
Observaciones: El tiempo se esta multiplicando por 1000 para convertir los microsegundos en milisegundos.
*/
void
filas (int cajas, int *tiempo_cajas)
{
  int i = 0;
  while (i < cajas)
    {
      printf ("\n\n Tiempo de la caja %d:", i + 1);
      scanf ("%d", &tiempo_cajas[i]);
      tiempo_cajas[i] = tiempo_cajas[i] * 1000;
      i++;
    }
  return;
}

/*
int llegada (int tiempo_cliente);
Descripcion: Procedimiento para capturar, por medio de la entrada estándar, el intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas
Recibe: int tiempo_cliente (intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas)
Devuelve: int tiempo_cliente (intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas)
Observaciones: El tiempo esta en microsegundos y para convertirlo a milisegundos se multiplica por 1000.
*/
int
llegada (int tiempo_cliente)
{
  printf ("\n\n Hora de llegada de los clientes (en milisegundos) : ");
  scanf ("%d", &tiempo_cliente);
  tiempo_cliente = tiempo_cliente * 1000;
  return tiempo_cliente;
}

/*
void imprimir_filas(int cajas, int fila, int cliente, int, x);
Descripcion: Procedimiento para imprimir, por medio de la salida estándar, a los clientes es sus respectivas cajas.
Recibe: int cajas (el número de cajas requeridas por el usuario), int fila (el número de la fila en la que está formado el cliente), int cliente (número del cliente) y int x (la coordenada en x donde imprimira el número de cliente).
Devuelve: int cliente (número del cliente). En pantalla aparecerá formado o siendo atendido en la caja que le corresponde.
Observaciones: Es una función larga
*/
void
imprimir_fila (int cajas, int fila, int cliente, int x)
{
  int i = 0;
  if (cajas == 1)
    {
      move (x, 58);
      printw ("%d", cliente);
    }
  if (cajas == 2)
    {
      if (fila == 0)
	{
	  move (x, 48);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 68);
	  printw ("%d", cliente);
	}
    }
  if (cajas == 3)
    {
      if (fila == 0)
	{
	  move (x, 38);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 58);
	  printw ("%d", cliente);
	}
      if (fila == 2)
	{
	  move (x, 78);
	  printw ("%d", cliente);
	}
    }
  if (cajas == 4)
    {
      if (fila == 0)
	{
	  move (x, 28);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 48);
	  printw ("%d", cliente);
	}
      if (fila == 2)
	{
	  move (x, 68);
	  printw ("%d", cliente);
	}
      if (fila == 3)
	{
	  move (x, 88);
	  printw ("%d", cliente);
	}
    }
  if (cajas == 5)
    {
      if (fila == 0)
	{
	  move (x, 18);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 38);
	  printw ("%d", cliente);
	}
      if (fila == 2)
	{
	  move (x, 58);
	  printw ("%d", cliente);
	}
      if (fila == 3)
	{
	  move (x, 78);
	  printw ("%d", cliente);
	}
      if (fila == 4)
	{
	  move (x, 98);
	  printw ("%d", cliente);
	}
    }

  if (cajas == 6)
    {
      if (fila == 0)
	{
	  move (x, 13);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 33);
	  printw ("%d", cliente);
	}
      if (fila == 2)
	{
	  move (x, 53);
	  printw ("%d", cliente);
	}
      if (fila == 3)
	{
	  move (x, 73);
	  printw ("%d", cliente);
	}
      if (fila == 4)
	{
	  move (x, 93);
	  printw ("%d", cliente);
	}
      if (fila == 5)
	{
	  move (x, 113);
	  printw ("%d", cliente);
	}
    }

  if (cajas == 7)
    {
      if (fila == 0)
	{
	  move (x, 12);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 27);
	  printw ("%d", cliente);
	}
      if (fila == 2)
	{
	  move (x, 42);
	  printw ("%d", cliente);
	}
      if (fila == 3)
	{
	  move (x, 57);
	  printw ("%d", cliente);
	}
      if (fila == 4)
	{
	  move (x, 72);
	  printw ("%d", cliente);
	}
      if (fila == 5)
	{
	  move (x, 87);
	  printw ("%d", cliente);
	}
      if (fila == 6)
	{
	  move (x, 102);
	  printw ("%d", cliente);
	}
    }
  if (cajas == 8)
    {
      if (fila == 0)
	{
	  move (x, 12);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 27);
	  printw ("%d", cliente);
	}
      if (fila == 2)
	{
	  move (x, 42);
	  printw ("%d", cliente);
	}
      if (fila == 3)
	{
	  move (x, 57);
	  printw ("%d", cliente);
	}
      if (fila == 4)
	{
	  move (x, 72);
	  printw ("%d", cliente);
	}
      if (fila == 5)
	{
	  move (x, 87);
	  printw ("%d", cliente);
	}
      if (fila == 6)
	{
	  move (x, 102);
	  printw ("%d", cliente);
	}
      if (fila == 7)
	{
	  move (x, 118);
	  printw ("%d", cliente);
	}
    }

  if (cajas == 9)
    {
      if (fila == 0)
	{
	  move (x, 10);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 25);
	  printw ("%d", cliente);
	}
      if (fila == 2)
	{
	  move (x, 40);
	  printw ("%d", cliente);
	}
      if (fila == 3)
	{
	  move (x, 55);
	  printw ("%d", cliente);
	}
      if (fila == 4)
	{
	  move (x, 70);
	  printw ("%d", cliente);
	}
      if (fila == 5)
	{
	  move (x, 85);
	  printw ("%d", cliente);
	}
      if (fila == 6)
	{
	  move (x, 100);
	  printw ("%d", cliente);
	}
      if (fila == 7)
	{
	  move (x, 115);
	  printw ("%d", cliente);
	}
      if (fila == 8)
	{
	  move (x, 130);
	  printw ("%d", cliente);
	}
    }

  if (cajas == 10)
    {
      if (fila == 0)
	{
	  move (x, 10);
	  printw ("%d", cliente);
	}
      if (fila == 1)
	{
	  move (x, 23);
	  printw ("%d", cliente);
	}
      if (fila == 2)
	{
	  move (x, 36);
	  printw ("%d", cliente);
	}
      if (fila == 3)
	{
	  move (x, 49);
	  printw ("%d", cliente);
	}
      if (fila == 4)
	{
	  move (x, 62);
	  printw ("%d", cliente);
	}
      if (fila == 5)
	{
	  move (x, 75);
	  printw ("%d", cliente);
	}
      if (fila == 6)
	{
	  move (x, 88);
	  printw ("%d", cliente);
	}
      if (fila == 7)
	{
	  move (x, 101);
	  printw ("%d", cliente);
	}
      if (fila == 8)
	{
	  move (x, 114);
	  printw ("%d", cliente);
	}
      if (fila == 9)
	{
	  move (x, 127);
	  printw ("%d", cliente);
	}
    }
}
