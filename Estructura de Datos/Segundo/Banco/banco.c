/*
AUTORES: 
Diego Ismael Barón Hernández. 
Rocío Vivia Delgadillo.
Jorge Gómez Reus.
Sergio Mercado Núñez.
Grupo 1CM15. 08 de noviembre del 2015.

DESCRIPCIÓN: Programa para simular la atención de personas en un banco, cuidando sean respetadas las políticas de atención del mismo y evitando que las personas dejen de ser atendidas. Políticas de atención:
• Los clientes del banco (personas con cuenta en ese banco),son atendidos por cualquier cajero y nunca dejan de ser atendidos por alguna caja.
• Los usuarios del banco (personas sin cuenta en ese banco), son atendidos según la disponibilidad de alguna caja, nunca permitiendo que pasen más de 5 personas de las otras dos filas sin que una persona de esta cola sea atendida.
• Los clientes preferentes (personas con más de una cuenta en ese banco y privilegios preferenciales), serán atendidos por cualquier cajero disponible con mayor prioridad que a los clientes y usuarios.

OBSERVACIONES: El programa recibe los intervalos de tiempo de los clientes, usuarios, preferenciales y las cajas por medio de la entrada estandar y no realiza verificacion de tipos por lo que una entrada incorrecta provocará un fallo del programa. Antes de correr el programa, en Linux, es necesaria la instalación de la biblioteca ncurses.h, en caso de que no se cuenta con ella, a través de la siguiente línea de comando:

sudo apt-get install libncurses4 libncurses5 libncurses5-dev libncursesw5 libncursesw5-dev ncurses-base ncurses-bin ncurses-hexedit ncurses-term

Si al usar este comando la terminal arroja errores con respecto a libncurses4, se recomienda retirarla de la instrucción e ingresar nuevamente el comando.

COMPILACIÓN: make
EJECUCIÓN: ./a.out (En Linux)
*/

//BIBLIOTECAS
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "TADColaDin.h"
#include "funciones.h"

//PROGRAMA PRINCIPAL
int
main (void)
{
  
  int cajas = 0;			//Almacena el número de cajas que el usuario haya elegido
  int tiempo_cliente = 0;		//Almacena el intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas
  int tiempo_usuarios = 0;		//Almacena el intervalo de tiempo en el que los usuarios aparecen en el mercado y se forman en una de las cajas
  int tiempo_general = 0;		//Almacena el menor tiempo de entre el de los clientes, los usuarios y los preferenciales
  int tiempo_preferenciales = 0;	//Almacena el intervalo de tiempo en el que los clientes preferenciales aparecen en el mercado y se forman en una de las cajas
  int i = 0;			//Variable usada para inicializar y recorrer las colas (cajas), para posicionar cajas y clientes gráficamente, y colocar un margen
  int x = 7;				//Almacena la posición en la que se imprimirá el cliente atendido en cada caja
  char s;				//Almacena el caracter ASCII a imprimir para generar el aspecto gráfico
  int cliente = 0;			//Almacena el número del cliente que ha ingresado el mercado
  int atendidos = 0;			//Almacena el número de clientes atendidos en las cajas. En caso de que su valor sea 5, un usuario es atendido
  int fila = 0;				//Almacena el número de la caja en el que cada uno de los clientes se irá formando
  int tiempo_cajas;			//Almacena el intervalo de tiempo en el que cada una de las cajas atiende a los clientes formados
  unsigned int tiempo = 0;		//Almacena el tiempo general desde que ingresa el primer cliente hasta el último
  cola c[10];				//Almacena las colas de las cajas
  elemento e;				//Almacena los elementos de las colas
  int no_cliente = 0;			//Almacena el número de cajas que no están atendiendo a ningún cliente

  bienvenida ();					//Se imprime, por medio de la salida estándar, un mensaje de bienvenida
  cajas = disponibles (cajas);				//Se hace un recorrido de 0 a 9
  tiempo_cajas = filas (tiempo_cajas);			//Captura el intervalo de tiempo de atención de las cajas
  tiempo_cliente = llegada_clientes (tiempo_cliente);	//Captura el intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en las cajas
  tiempo_usuarios = llegada_usuarios (tiempo_usuarios); //Captura el intervalo de tiempo en el que los usuarios aparecen en el mercado y se forman en las cajas
  //Captura el intervalo de tiempo en el que los clientes preferenciales aparecen en el mercado y se forman en las cajas
  tiempo_preferenciales = llegada_preferencia (tiempo_preferenciales);

  for (i = 0; i < 10; i = i + 1)	//Se hace un recorrido de 0 a 9
    {
      Initialize (&c[i]);		//Se inicializa la cola de cada caja
    }
  initscr ();			/*Esta función  inicializa  ncurses. Para todos los programas
				debemos siempre inicializar  ncurses y luego finalizarla, como
				veremos adelante*/

  tiempo = tiempo_cliente;				//Se actualiza el tiempo con el tiempo de los clientes
  if (tiempo > tiempo_usuarios)				//Si el tiempo es mayor que el tiempo de los usuarios
    {
      tiempo = tiempo_usuarios;				//Se actualiza el tiempo con el tiempo de los usuarios
    }
  if (tiempo > tiempo_preferenciales)			//Si el tiempo es mayor que el tiempo de los preferenciales
    {
      tiempo = tiempo_preferenciales;			//Se actualiza el tiempo con el tiempo de los preferenciales
    }
  if (tiempo == tiempo_usuarios)			//Si el tiempo es igual al tiempo de los usuarios
    {
      tiempo = tiempo_usuarios;				//Se actualiza el tiempo con el tiempo de los usuarios
    }
  if (tiempo == tiempo_preferenciales)			//Si el tiempo es igual al tiempo de los preferenciales
    {
      tiempo = tiempo_preferenciales;			//Se actualiza el tiempo con el tiempo de los preferenciales
    }

  tiempo_general = tiempo;				//Se actualiza el tiempo general con el tiempo menor de entre el de los usuarios, clientes y preferenciales

  while (1)						//Repite el ciclo sin parar
    {
      s = 95;						//caracter ascci horizontal
      for (i = 1; i <= 140; i++)
	{
	  //linea horizontal superior
	  move (1, i);					//Aqui estamos moviendo el cursor para a linea 1 columna i.
	  printw ("%c", s);				//Imprimimos un texto en la posición establecida.
	  //linea horizontal inferior
	  move (40, i);					//Aqui estamos moviendo el cursor para a linea 40 columna i.
	  printw ("%c", s);				//Imprimimos un  texto en la posición establecida.
	}
      s = 124;						//caracter ascci vertical
      for (i = 2; i <= 40; i++)
	{
	  //linea vertical izquierda
	  move (i, 1);
	  printw ("%c", s);
	  //linea vertical derecha
	  move (i, 140);
	  printw ("%c", s);
	}

      // Aqui empieza la funcion que imprime las cajas.
      Imprimir_cajas (cajas);
      //Aqui termina la impresion de cajas.
      usleep (tiempo_general);
      srand (time (NULL));
      /*Si el tiempo es un múltiplo del tiempo de los clientes preferenciales, si el tiempo es un múltiplo del tiempo de los clientes, si el tiempo es un múltiplo 	 del tiempo de los usuarios, y los clientes y preferenciales atendidos son distintos a cinco*/
      if ((tiempo % tiempo_preferenciales == 0)
	  && (tiempo % tiempo_cliente == 0)
	  && (tiempo % tiempo_usuarios == 0) && (atendidos != 5))
	{
	  cliente++;					//Incrementar el número de clientes
	  e.n = cliente;				//Se actualiza el número de cliente en el elemento de la cola en turno
	  e.tipo = 'P';					//Se actualiza la categoría del cliente en el elemento de la cola en turno
	  fila = rand () % cajas;			//Se elige aleatoriamente una fila para formar al cliente almacenado en elemento                            
	  Queue (&c[fila], e);				//Se forma al cliente en la fila seleccionada
	}
      else
	{
	  //Si el tiempo es un múltiplo del tiempo de los clientes preferenciales, y los clientes y preferenciales atendidos son distintos a cinco
	  if ((tiempo % tiempo_preferenciales == 0) && (atendidos != 5))
	    {
	      cliente++;				//Incrementar el número de clientes
	      e.n = cliente;				//Se actualiza el número de cliente en el elemento de la cola en turno
	      e.tipo = 'P';				//Se actualiza la categoría del cliente en el elemento de la cola en turno
	      fila = rand () % cajas;			//Se elige aleatoriamente una fila para formar al cliente almacenado en elemento
	      Queue (&c[fila], e);			//Se forma al cliente en la fila seleccionada
	      atendidos++;				//Se incrementa el número de clientes y preferenciales atendidos 
	    }
	  //Si el tiempo es un múltiplo del tiempo de los clientes, y los clientes y preferenciales atendidos son distintos a cinco
	  if ((tiempo % tiempo_cliente == 0) && (atendidos != 5))
	    {
	      cliente++;				//Incrementar el número de clientes
	      e.n = cliente;				//Se actualiza el número de cliente en el elemento de la cola en turno
	      e.tipo = 'C';				//Se actualiza la categoría del cliente en el elemento de la cola en turno
	      fila = rand () % cajas;			//Se elige aleatoriamente una fila para formar al cliente almacenado en elemento
	      Queue (&c[fila], e);			//Se forma al cliente en la fila seleccionada
	      atendidos++;				//Se incrementa el número de clientes y preferenciales atendidos
	    }
	  //Si el tiempo es un múltiplo del tiempo de los usuarios
	  if (tiempo % tiempo_usuarios == 0)
	    {
	      cliente++;				//Incrementar el número de clientes
	      e.n = cliente;				//Se actualiza el número de cliente en el elemento de la cola en turno
	      e.tipo = 'U';				//Se actualiza la categoría del cliente en el elemento de la cola en turno
	      fila = rand () % cajas;			//Se elige aleatoriamente una fila para formar al cliente almacenado en elemento
	      Queue (&c[fila], e);			//Se forma al cliente en la fila seleccionada
	      if (atendidos == 5)			//Se el número de clientes y preferenciales atendidos es igual a cinco
		{
		  atendidos = 0;			//Se reinicia el contador de los clientes y preferenciales atendidos
		}
	    }
	}

      for (i = 0; i < cajas; i++)			//Se hace un recorrido por el número de cajas disponibles
	{
	  if ((tiempo % tiempo_cajas == 0) && !Empty (&c[i]))	//Si el tiempo es un múltiplo del tiempo de la caja y esta última no está vacía
	    {
	      e = Dequeue (&c[i]);				//Se desencola un elemento de la caja en turno
	      imprimir_filas (cajas, fila, e.tipo, e.n, x);	//Imprime al cliente que está siendo atendido a un lado de la caja correspondiente
		if (e.tipo == 'P' || 'U')			//Si el tipo de cliente es cliente preferencial o usuario
	    	 {
	      	   no_cliente++;				//Se actualiza el contador de cajas sin clientes
	    	 }
	    }
	}

        if (no_cliente == cajas)			//Si no hay ningún cliente en caja
	 {
	   cliente++;					//Incrementar el número de clientes
	   e.n = cliente;				//Se actualiza el número de cliente en el elemento de la cola en turno
	   e.tipo = 'C';				//Se actualiza la categoría del cliente en el elemento de la cola en turno
	   fila = rand () % cajas;			//Se elige aleatoriamente una fila para formar al cliente almacenado en elemento                            
	   Queue (&c[fila], e);				//Se forma al cliente en la fila seleccionada
	   atendidos++;					//Se incrementa el número de clientes y preferenciales atendidos
	 }
      no_cliente = 0;
      tiempo = tiempo + tiempo_general;				/*Se actualiza el tiempo con un incremento del tiempo menor de entre el de los usuarios, clientes y 									preferenciales*/
      refresh ();
    }

  getch ();							//Saldrá del programa hasta pulsada una tecla
  endwin ();				//Siempre que finalizamos un programa con una biblioteca ncurses, debemos ejecutar e comando endwin
}

