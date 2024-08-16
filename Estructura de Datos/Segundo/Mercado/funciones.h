/*
AUTORES: 
Diego Ismael Barón Hernández. 
Rocío Vivia Delgadillo.
Jorge Gómez Reus.
Sergio Mercado Núñez.
Grupo 1CM15. 08 de noviembre del 2015.

DESCRIPCIÓN: Cabecera de las funciones específicas para el programa mercado
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

//DECLARACIÓN DE FUNCIONES
/*Procedimiento para imprimir, por medio de la salida estándar, las cajas deseadas por el usuario
(Recibe la referencia del número de cajas requeridas por el usuario)*/
void Imprimir_cajas (int);
/*Procedimiento para capturar, por medio de la entrada estándar, el nombre del supermercado
(Recibe la referencia a la cadena del nombre del supermercado)*/
char* titulo (char*);
/*Procedimiento para capturar, por medio de la entrada estándar, el numero de cajas requeridas por el usuario
(Recibe la referencia del número de cajas requeridas por el usuario)*/
int disponibles (int); 
/*Procedimiento para capturar el tiempo de atencion que tendrá cada una de las cajas abiertas
(Recibe la referencia del número de cajas requeridas por el usuario y el arreglo de los tiempos de las cajas)*/
void filas (int, int*);
/*Procedimiento para capturar, por medio de la entrada estándar, el intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas
(Recibe la referencia del intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas)*/
int llegada (int);
/*Procedimiento para imprimir, por medio de la salida estándar, a los clientes es sus respectivas cajas
(Recibe la referencia del número de cajas requeridas por el usuario, el número de la fila en la que está formado el cliente, el número del cliente y la coordenada en x donde imprimira el número de cliente).*/
void imprimir_fila (int, int, int, int);
