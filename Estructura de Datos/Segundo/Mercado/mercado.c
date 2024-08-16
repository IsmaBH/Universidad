/*
AUTORES: 
Diego Ismael Barón Hernández. 
Rocío Vivia Delgadillo.
Jorge Gómez Reus.
Sergio Mercado Núñez.
Grupo 1CM15. 08 de noviembre del 2015.

DESCRIPCIÓN: Programa para simular la atención de clientes en un supermercado, el cuál deberá de atender al menos 100 clientes por día para no tener perdidas, por lo que una vez que ya se atendieron a más de 100 personas y no hay gente formada en las cajas se cierra la tienda. Mientras no se cierre la tienda, las personas podrán seguir llegando a las cajas

OBSERVACIONES: El programa recibe los intervalos de tiempo de los clientes y las cajas por medio de la entrada estandar y no realiza verificacion de tipos por lo que una entrada incorrecta provocará un fallo del programa; así mismo, los espacios en el campo del nombre del supermercado están soportados. Antes de correr el programa, en Linux, es necesaria la instalación de la biblioteca ncurses.h, en caso de que no se cuenta con ella, a través de la siguiente línea de comando:

sudo apt-get install libncurses4 libncurses5 libncurses5-dev libncursesw5 libncursesw5-dev ncurses-base ncurses-bin ncurses-hexedit ncurses-term

Si al usar este comando la terminal arroja errores con respecto a libncurses4, se recomienda retirarla de la instrucción e ingresar nuevamente el comando.

COMPILACIÓN: make
EJECUCIÓN: ./a.out (En Linux)
*/

//BIBLIOTECA
#include <ncurses.h>		
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "TADColaEst.h"
#include "funciones.h"
void Salir (void);		//Esta funcion cerrará el programa

//PROGRAMA PRINCIPAL
int
main (void)
{
  int i;		        //Variable usada para inicializar y recorrer las colas (cajas), para posicionar cajas y clientes gráficamente, y colocar un margen
  char s;			//Almacena el caracter ASCII a imprimir para generar el aspecto gráfico
  int tiempo_cliente = 0;	//Almacena el intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas
  char nombre[100];		//Almacena el nombre dado por el usuario al mercado 
  int clientes_atendidos = 0;	//Almacena el número de clientes atendidos en las cajas
  int cajas = 0;		//Almacena el número de cajas que el usuario haya elegido
  int cliente = 0;		//Almacena el número del cliente que ha ingresado el mercado
  int tiempo_cajas[10];		//Almacena el intervalo de tiempo en el que cada una de las cajas atiende a los clientes formados
  int fila = 0;			//Almacena el número de la caja en el que cada uno de los clientes se irá formando
  int x = 0;			//Almacena la posición en la que se imprimirá el cliente atendido en cada caja
  int todas = 0;		//Almacena el número de cajas vacías
  unsigned int tiempo = 0;	//Almacena el tiempo general desde que ingresa el primer cliente hasta el último
  cola c[10];			//Almacena las colas de las cajas
  elemento e;			//Almacena los elementos de las colas

  titulo (nombre);				//Captura el nombre del supermercado
  cajas = disponibles (cajas);			//Captura el número de cajas solicitadas por el usuario
  filas (cajas, tiempo_cajas);			//Captura el intervalo de tiempo de atención de cada una de las cajas
  tiempo_cliente = llegada (tiempo_cliente);	//Captura el intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en las cajas
  tiempo = tiempo_cliente;			//Se almacena el tiempo de los clientes en el tiempo general del supermercado

  for (i = 0; i < 10; i = i + 1)		//Se hace un recorrido de 0 a 9
    {
      Initialize (&c[i]);			//Se inicializa la cola de cada caja
    }
  initscr ();			/*Esta función  inicializa  ncurses. Para todos los programas
				debemos siempre inicializar  ncurses y luego finalizarla, como
				veremos adelante*/

  //Repetir hasta que  el número de clientes atendidos sea cien o más y todas las cajas estén vacías
    while (!(clientes_atendidos >= 100) && (todas != cajas))
    //while ((clientes_atendidos <= 100) || (todas != cajas))
    {
      s = 95;					//caracter ascci horizontal
      for (i = 1; i <= 140; i++)
	{
	  //linea horizontal superior
	  move (1, i);				//Aqui estamos moviendo el cursor para a linea 1 columna i
	  printw ("%c", s);			//Imprimimos un texto en la posición establecida
	  //linea horizontal inferior
	  move (40, i);				//Aqui estamos moviendo el cursor para a linea 40 columna i
	  printw ("%c", s);			//Imprimimos un  texto en la posición establecida
	}
      s = 124;					//caracter ascci vertical
      for (i = 2; i <= 40; i++)
	{
	  //linea vertical izquierda
	  move (i, 1);
	  printw ("%c", s);
	  //linea vertical derecha
	  move (i, 140);
	  printw ("%c", s);
	}
      // Aqui empieza la funcion que imprime el titulo
      move (2, 55);		/* x , y */
      printw ("%s", nombre);
      // Aqui termina la funcion que imprime el titulo
      // Aqui empieza la funcion que imprime las cajas
      Imprimir_cajas (cajas);
      //Aqui termina la impresion de cajas
      move (3, 45);		/* x , y */
      printw ("Numero de clientes atendidos:");
      if (clientes_atendidos > 0)		//Si el número de clientes atendidos es mayor a cero
	{
	  printw ("%d", clientes_atendidos);
	}

      usleep (tiempo_cliente);			//Espera el tiempo de los cliente
      srand (time (NULL));
      cliente++;				//Incrementar el numero de clientes
      e.n = cliente;				//Se actualiza el número de cliente en el elemento de la cola en turno
      fila = rand () % cajas;			//Se elige aleatoriamente una fila para formar al cliente almacenado en elemento
      Queue (&c[fila], e);			//Se forma al cliente en la fila seleccionada

      for (i = 0; i < cajas; i++)		//Se hace un recorrido por el número de cajas disponibles
	{
	  if ((tiempo % tiempo_cajas[i] == 0) && !Empty (&c[i]))	//Si el tiempo general es un múltiplo del tiempo de la caja y esta última no está vacía
	    {
	      x = 7;				//Se asigna la posición de impresión del cliente en pantalla
	      e = Dequeue (&c[i]);   		//Se desencola un elemento de la caja en turno
	      imprimir_fila (cajas, fila, e.n, x);		//Imprime al cliente que está siendo atendido a un lado de la caja correspondiente
	      clientes_atendidos = clientes_atendidos + 1;	//Actualiza el número de clientes atendidos
	    }
	}

      if (clientes_atendidos >= 100)		//Si el número de clientes atendidos es mayor o igual que 100
	{
	  for (i = 0; i < cajas; i++)		//Se hace un recorrido por el número de cajas disponibles
	    {
	      if (!Empty (&c[i]))		//Si la caja en turno está vacía
		{
		  todas = todas + 1;		//Actualiza el número de cajas vacías
		}
	    }
	}

      refresh ();
    }
  move (50, 45);		//Aqui estamos moviendo el cursor para a linea 50 columna 45
  printf ("CERRADO!!\n");
  getch ();			//Saldrá del programa hasta pulsada una tecla
  Salir ();			//Salir del programa
}

/*
void Salir (void);
Descripción: Procedimiento para salir del programa 
Recibe: 
Devuelve: 
Observaciones: Siempre que finalizamos un programa con una biblioteca ncurses, debemos ejecutar e comando endwin.
*/
void
Salir ()
{
  endwin ();		
  return;
}
