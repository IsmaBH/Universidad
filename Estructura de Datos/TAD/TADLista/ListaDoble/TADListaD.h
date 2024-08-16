/*
DECLARACIÓN DE LA OPERACIONES DEL TAD LISTA (TADLista.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Noviembre 2015
VERSIÓN: 1.0

DESCRIPCIÓN: TAD lista o (list)
Estructura de datos en la que se cumple:
Los elementos se consultan, añaden y se remueven con base en posiciones 
dentro de un arreglo lineal el cual cuenta con un frente o cabeza 
y un final o cola.

OBSERVACIONES: Este archivo solo incluye las estructuras, tipos de datos y
declaración de las operaciones del TAD  Lista.

EL CODIGO QUE IMPLEMENTA LAS FUNCIONES ES EL ARCHIVO: TADListaDoblementeLigada.c
*/
#include <stdio.h>

#define TRUE	1
#define FALSE	0

#define ADELANTE	1
#define ATRAS		0

//Estructura elemento (Modificable por el usuario)
typedef struct elemento
{
	char nombre[46];
}elemento;

//Tipo de dato boolean (Modelado con un char)
typedef char boolean;

//Estructura de un NODO DOBLEMENTE LIGADO(No modificar)
typedef struct nodo
{
	elemento e;	
	struct nodo *adelante;	
	struct nodo* atras;

}nodo;

//Estructura de una LISTA(No modificar)
typedef struct lista
{
	nodo *frente;
	nodo *final;
	unsigned long tam;
}lista;

typedef nodo* posicion;

//Operaciones de construcción
void Initialize(lista *l); /* X */
void Destroy(lista *l); /*X*/
//Operaciones de posicionamiento y busqueda
posicion Final(lista *l);/*X*/
posicion First(lista *l);/*X*/
posicion Following(lista *l, posicion p);/*X*/
posicion Previous(lista *l, posicion p);/*X*/
posicion Search(lista *l, elemento e);/*X*/
//Operación de consulta
elemento Position(lista *l, posicion p);/*X*/
elemento Element(lista *l, unsigned long n);/*X*/
unsigned long Size(lista *l);/*X*/
boolean Empty(lista *l);/*X*/
boolean ValidatePosition(lista *l, posicion p);/*X*/
//Operaciones de modificación
void Insert(lista *l, elemento e, posicion p,boolean b);/*X*/
void Add(lista *l,elemento e);/*X*/
void Remove(lista *l,posicion p);/*X*/
void Replace(lista *l,posicion p, elemento e);/*X*/
