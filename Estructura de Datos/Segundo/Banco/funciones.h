/*
AUTORES: 
Diego Ismael Barón Hernández. 
Rocío Vivia Delgadillo.
Jorge Gómez Reus.
Sergio Mercado Núñez.
Grupo 1CM15. 08 de noviembre del 2015.

DESCRIPCIÓN: Cabecera de las funciones específicas para el programa banco
*/

#include <stdio.h>
#include <ncurses.h>

//DECLARACIÓN DE FUNCIONES
//Proceso que muestra mensaje de Bienvenida
void bienvenida (void);
/*Procedimiento para capturar, por medio de la entrada estándar, el numero de cajas requeridas por el usuario
(Recibe la referencia del número de cajas requeridas por el usuario)*/
int disponibles (int cajas);
/*Procedimiento para capturar el intervalo de tiempo de atención de las cajas
(Recibe la referencia del número de cajas requeridas por el usuario y el intervalo de tiempo de atención de las cajas)*/
int filas (int);
/*Procedimiento para capturar, por medio de la entrada estándar, el intervalo de tiempo en el que los usuarios aparecen en el mercado y se forman en una de las cajas
(Recibe la referencia del intervalo de tiempo en el que los usuarios aparecen en el mercado y se forman en una de las cajas)*/
int llegada_usuarios (int);
/*Procedimiento para capturar, por medio de la entrada estándar, el intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas
(Recibe la referencia del intervalo de tiempo en el que los clientes aparecen en el mercado y se forman en una de las cajas)*/
int llegada_clientes (int);
/*Procedimiento para capturar, por medio de la entrada estándar, el intervalo de tiempo en el que los clientes preferenciales aparecen en el mercado y se forman en una de las cajas
(Recibe la referencia del intervalo de tiempo en el que los clientes preferenciales aparecen en el mercado y se forman en una de las cajas)*/
int llegada_preferencia (int);
/*Procedimiento para imprimir, por medio de la salida estándar, a los clientes es sus respectivas cajas
(Recibe la referencia del número de cajas requeridas por el usuario, el número de la fila en la que está formado el cliente, el número del cliente y la coordenada en x donde imprimira el número de cliente).*/
void imprimir_fila (int, int, char, int, int);
/*Procedimiento para imprimir, por medio de la salida estándar, las cajas deseadas por el usuario
(Recibe la referencia del número de cajas requeridas por el usuario)*/
void imprimir_cajas (int); 
