#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "TADColaDin.h"


/*
int disponibles (int cajas);
Descripcion: Procedimiento para capturar, por medio de la entrada estándar, el numero de cajas requeridas por el usuario
Recibe: int cajas (el número de cajas requeridas por el usuario)
Devuelve: int cajas (el número de cajas requeridas por el usuario)
Observaciones: 
*/
int disponibles (int cajas)
{
  printf ("\n\n Introducir número de cajas abiertas : ");
  scanf ("%d", &cajas);
  return cajas;
}

/*
void filas (int tiempo_cajas);
Descripcion: Procedimiento para capturar el intervalo de tiempo de atención de las cajas
Recibe: int tiempo_cajas (Referencia al intervalo de tiempo de atención de las cajas)
Devuelve: int tiempo_cajas (Referencia al intervalo de tiempo de atención de las cajas)
Observaciones: El tiempo se esta multiplicando por 1000 para convertir los microsegundos en milisegundos.
*/
int filas ( int tiempo_cajas)
{
  printf ("\n\n Tiempo de las cajas: ");
  scanf ("%d", &tiempo_cajas);
  tiempo_cajas = tiempo_cajas * 1000;
  return tiempo_cajas;
}

/*
int llegada (int tiempo_cliente);
Descripcion: Procedimiento para capturar, por medio de la entrada estándar, el intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas
Recibe: int tiempo_cliente (intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas)
Devuelve: int tiempo_cliente (intervalo de tiempo en el que los clientes aparecen en el mercado y se 
forman en una de las cajas)
Observaciones: El tiempo esta en microsegundos y para convertirlo a milisegundos se multiplica por 1000.
*/
int llegada_clientes (int tiempo_cliente)
{
  printf ("\n\n Hora de llegada de los usuarios (en milisegundos) : ");
  scanf ("%d", &tiempo_cliente);
  tiempo_cliente = tiempo_cliente * 1000;  
  return tiempo_cliente;
}

/*
int llegada (int tiempo_usuarios);
Descripcion: Procedimiento para capturar, por medio de la entrada estándar, el intervalo de tiempo en el que los usuarios aparecen en el mercado y se forman en una de las cajas
Recibe: int tiempo_usuarios (intervalo de tiempo en el que los usuarios aparecen en el mercado y se forman en una de las cajas)
Devuelve: int tiempo_usuarios (intervalo de tiempo en el que los usuarios aparecen en el mercado y se forman en una de las cajas)
Observaciones: El tiempo esta en microsegundos y para convertirlo a milisegundos se multiplica por 1000.
*/
int llegada_usuarios (int tiempo_usuarios)
{
  printf ("\n\n Hora de llegada de los clientes (en milisegundos) : ");
  scanf ("%d", &tiempo_usuarios);
  tiempo_usuarios = tiempo_usuarios * 1000;  
  return tiempo_usuarios;
}

/*
int llegada (int tiempo_preferenciales);
Descripcion: Procedimiento para capturar, por medio de la entrada estándar, el intervalo de tiempo en el que los clientes preferenciales aparecen en el mercado y se forman en una de las cajas
Recibe: int tiempo_preferenciales (intervalo de tiempo en el que los clientes preferenciales aparecen en el mercado y se forman en una de las cajas)
Devuelve: int tiempo_preferenciales (intervalo de tiempo en el que los clientes preferenciales aparecen en el mercado y se forman en una de las cajas)
Observaciones: El tiempo esta en microsegundos y para convertirlo a milisegundos se multiplica por 1000.
*/
int llegada_preferencia (int tiempo_preferenciales)
{
  printf ("\n\n Hora de llegada de los preferenciales (en milisegundos) : ");
  scanf ("%d", &tiempo_preferenciales);
  tiempo_preferenciales = tiempo_preferenciales * 1000;  
  return tiempo_preferenciales;
}

/*
void imprimir_filas(int cajas, int fila, char tipo, int aux, int, x);
Descripcion: Procedimiento para imprimir, por medio de la salida estándar, a los clientes es sus respectivas cajas.
Recibe: int cajas (el número de cajas requeridas por el usuario), int fila (el número de la fila en la que está formado el cliente), char tipo (categoría: usuario, cliente y preferencial), int aux (número del cliente) y int x (la coordenada en x donde imprimira el número de cliente).
Devuelve: int cliente (número del cliente). En pantalla aparecerá formado o siendo atendido en la caja que le corresponde.
Observaciones: Es una función larga
*/
void imprimir_filas (int cajas, int fila, char tipo, int aux, int x)
{
  int i = 0;
 // int x = 7;
  if (cajas == 1)
     {
       //int x = 7;
       move(x,58);
       printw ("%d%c", aux, tipo);
       //++x;
     }
  if (cajas == 2)
     {
        //int x = 7;
        if (fila == 0)
         {
         move(x,48);
         printw ("%d%c", aux, tipo);
         }
        if (fila == 1)
          {
         move(x,68);
         printw ("%d%c", aux, tipo);
          }
     }
  if (cajas == 3)
     {
       //int x = 7;
       if (fila == 0)
          {
           move(x,38);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 1)
          {
           move(x,58);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 2)
          {
           move(x,78);
           printw ("%d%c", aux, tipo);
          }
     } 
  if (cajas == 4)
     {
       //int x = 7;
       if (fila == 0)
          {
           move(x,28);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 1)
          {
           move(x,48);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 2)
          {
           move(x,68);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 3)
          {
           move(x,88);
           printw ("%d%c", aux, tipo);
          }
     }
  if (cajas == 5)
     {
       //int x = 7;
       if (fila == 0)
          {
           move(x,18);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 1)
          {
           move(x,38);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 2)
          {
           move(x,58);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 3)
          {
           move(x,78);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 4)
          {
           move(x,98);
           printw ("%d%c", aux, tipo); 
          }
     }
  
  if (cajas == 6)
     {
       //int x = 7;
       if (fila == 0)
          {
           move(x,13);
           printw ("%d%c", aux, tipo); 
          }
       if (fila == 1)
          {
           move(x,33);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 2)
          {
           move(x,53);
           printw ("%d%c", aux, tipo); 
          }
       if (fila == 3)
          {
           move(x,73);
           printw ("%d%c", aux, tipo); 
          }
       if (fila == 4)
          {
           move(x,93);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 5)
          {
           move(x,113);
           printw ("%d%c", aux, tipo); 
          }
     }

  if (cajas == 7)
     {
       //int x = 7;
       if (fila == 0)
          {
           move(x,12);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 1)
          {
           move(x,27);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 2)
          {
           move(x,42);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 3)
          {
           move(x,57);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 4)
          {
           move(x,72);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 5)
          {
           move(x,87);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 6)
          {
           move(x,102);
           printw ("%d%c", aux, tipo);
          }
     }
  if (cajas == 8)
     {
       //int x = 7;
       if (fila == 0)
          {
           move(x,12);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 1)
          {
           move(x,27);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 2)
          {
           move(x,42);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 3)
          {
           move(x,57);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 4)
          {
           move(x,72);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 5)
          {
           move(x,87);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 6)
          {
           move(x,102);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 7)
          {
           move(x,118);
           printw ("%d%c", aux, tipo);
          }
     }

  if (cajas == 9)
     {
       //int x = 7;
       if (fila == 0)
          {
           move(x,10);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 1)
          {
           move(x,25);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 2)
          {
           move(x,40);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 3)
          {
           move(x,55);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 4)
          {
           move(x,70);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 5)
          {
           move(x,85);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 6)
          {
           move(x,100);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 7)
          {
           move(x,115);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 8)
          {
           move(x,130);
           printw ("%d%c", aux, tipo);
          }
     }

  if (cajas == 10)
     {
       //int x = 7;
       if (fila == 0)
          {
           move(x,10);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 1)
          {
           move(x,23);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 2)
          {
           move(x,36);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 3)
          {
           move(x,49);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 4)
          {
           move(x,62);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 5)
          {
           move(x,75);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 6)
          {
           move(x,88);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 7)
          {
           move(x,101);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 8)
          {
           move(x,114);
           printw ("%d%c", aux, tipo);
          }
       if (fila == 9)
          {
           move(x,127);
           printw ("%d%c", aux, tipo); 
          }
     }
}

