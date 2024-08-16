/*
IMPLEMENTACION DE LA LIBRERIA DEL TAD LISTA DOBLEMENTE LIGADA (TADListaDoblementeLigada.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Noviembre 2015
VERSIÓN: 1.0

DESCRIPCIÓN: TAD Lista o (list).
Estructura de datos en la que se cumple:
Los elementos se consultan, añaden y se remueven con base en posiciones 
dentro de un arreglo lineal el cual cuenta con un frente o cabeza 
y un final o cola.

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADListaDoblementeLigada.c
*/

//LIBRERIAS
#include <stdlib.h>
#include <string.h>
#include "TADListaDoblementeLigada.h"


//Operaciones de construcción


/*
void Initialize(lista * l);
Descripción: Inicializar lista (Iniciar una lista para su uso).
Recibe: lista * l (Referencia a la lista "l" a operar).
Devuelve:
Observaciones: El usuario ha creado una lista y l tiene la referencia a ella, 
de no ocurrir se suscitará un error.
*/
void Initialize(lista *l)
{
	(*l).frente=NULL;
	l->final=NULL;
	l->tam=0;
	return;
}


/*
void Destroy(lista * l);
Descripción: Recibe una lista y la libera completamente.
Recibe: lista * l (Referencia a la lista "l" a operar).
Devuelve:
Observaciones: La lista se destruye y se inicializa.
*/
void Destroy(lista *l)
{
	nodo *aux;
	while(l->frente!=NULL)
	{
		aux=l->frente->atras;
		free(l->frente);
		l->frente=aux;
	}
	l->final=NULL;
	l->tam=0;
	return;
}


//Operación de consulta


/*
elemento Position (lista * l, posicion p);
Descripción: Recibe una lista y devuelve el elemento que se encuentra en la posición dada.
Recibe: lista * l (Referencia a la lista "l") y posicion p (Referencia a la posición "p").
Devuelve: el elemento que se encuentra en la posición dada.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada, la 
posición dada es válida de lo contrario el programa terminará. *No se modifica el TAD.
*/
elemento Position(lista *l, posicion p)
{
	if(ValidatePosition(l,p)==TRUE)
	{
		return p->e;
	}
	else
	{
		exit(1);
	}
}


/*
elemento Element (lista * l, unsigned long n);
Descripción: Recibe una lista, el número de un elemento dentro de la misma y devuelve el elemento
al que le corresponde esa ubicación.
Recibe: lista * l (Referencia a la lista "l") y unsigned long n (Referencia a la ubicación "n").
Devuelve: el elemento que se encuentra en la ubicación dada.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada, el número
de elemento es válido de lo contrario el programa terminará. *No se modifica el TAD.
*/
elemento Element(lista *l, unsigned long n)
{
	nodo *aux;
	unsigned long i;
	
	aux=l->frente;
	
	if(aux!=NULL&&n>0&&n<=Size(l))
	{
		for(i=1;i<n&&aux!=NULL;i++)
		{
			aux=aux->atras;
		}		
		
		return aux->e;
	}
	else
	{
		exit(1);
	}
}


/*
unsigned long Size (lista * l);
Descripción: Recibe una lista y devuelve el número de elementos que hay en esta.
Recibe: lista * l (Referencia a la lista "l").
Devuelve: unsigned long (Tamaño de la lista)
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada, esta 
deberá tener elementos de lo contrario devolverá ERROR. *No se modifica el TAD.
*/
unsigned long Size(lista *l)
{
	return l->tam;	
}


/*
boolean Empty (lista * l);
Descripción: Recibe una lista y TRUE si la lista está vacía y FALSE en caso contrario.
Recibe: lista * l (Referencia a la lista "l").
Devuelve: boolean TRUE O FALSE.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada.
*/
boolean Empty(lista *l)
{
	if(l->frente==NULL && l->final==NULL && l->tam==0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/*
boolean ValidatePosition (lista * l, posicion p);
Descripción: Recibe una lista y TRUE si la posición está en la lista y FALSE en caso contrario.
Recibe: lista * l (Referencia a la lista "l") y posicion p (Referencia a la posición "p").
Devuelve: boolean TRUE O FALSE.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada.
*/
boolean ValidatePosition(lista *l, posicion p)
{
	nodo *aux;
	
	aux=l->frente;
	while(aux!=p&&aux!=NULL)
	{
		aux=aux->atras;
	}
	
	if(aux==NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}


//Operaciones de modificación


/*
void Insert (lista * l, elemento e, posicion p, boolean b);
Descripción: Recibe una lista, un elemento, una posición y TRUE si el elemento será insertado atrás 
de la posición dada y FALSE si lo insertará adelante; a continuación inserta el elemento en la lista.
Recibe: lista * l (Referencia a la lista "l"), posicion p (Referencia a la posición "p"), elemento e 
(Referencia a la elemento "e") y boolean b (Referencia al boolean "b").
Devuelve:
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada.
*/
void Insert(lista *l, elemento e, posicion p,boolean b)
{
	nodo* aux;
	//Crear al nodo
	aux=malloc(sizeof(nodo));
	aux->e=e;

	//Validar la posicion
	if(ValidatePosition(l,p)==TRUE)
	{			
		//Atras de P
		if(b==TRUE)
		{
			//Si P es el final de la lista
			if(l->final==p)
			{
				l->final=aux;
			}
			
			aux->atras=p->atras;
			p->atras=aux;
			aux->adelante=p;
			aux->atras->adelante=aux; //*(aux->atras).adelante=aux;
		}
		else
		{
			//Si P es el frente de la lista
			if(l->frente==p)
			{
				l->frente=aux;
			}
			
			aux->adelante=p->adelante;
			aux->atras=p;
			p->adelante=aux;
			aux->adelante->atras=aux;
			
		}
	}		
	else
	{
		//Insertar al frente de la lista
		//Si es vacia
		if(l->frente==NULL&&l->final==NULL)
		{
			aux->atras=NULL;
			aux->adelante=NULL;
			l->frente=aux;
			l->final=aux;		
		}
		//Si no es vacia
		else
		{
			aux->adelante=NULL;
			aux->atras=l->frente;
			l->frente->adelante=aux;
			l->frente=aux;
		}
	}
	
	l->tam++;
	return;
}


/*
void Add (lista * l, elemento e);
Descripción: Recibe una lista y agrega al elemento dado al final de la misma.
Recibe: lista * l (Referencia a la lista "l") y elemento e (Referencia a la elemento "e").
Devuelve: 
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada.
*/
void Add(lista *l,elemento e)
{
	nodo* aux;
	//Crear al nodo
	aux=malloc(sizeof(nodo));
	aux->e=e;

	//Insertar al final de la lista
	//Si es vacia
	if(l->frente==NULL&&l->final==NULL)
	{
		aux->atras=NULL;
		aux->adelante=NULL;
		l->frente=aux;
		l->final=aux;		
	}
	//Si no es vacia agregar al final
	else
	{
		aux->atras=NULL;
		aux->adelante=l->final;
		l->final->atras=aux;
		l->final=aux;
	}
	
	l->tam++;
	return;
}


/*
void Remove (lista * l, posicion p);
Descripción: Recibe una lista y elimina al elemento que se encuentra en la posición dada.
Recibe: lista * l (Referencia a la lista "l") y posicion p (Referencia a la posición "p").
Devuelve: 
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada. La 
posición dada es válida de lo contrario el programa terminará.
*/
void Remove(lista *l,posicion p)
{
	//Validar la posicion
	if(ValidatePosition(l,p)==TRUE)
	{
		//Si P es el frente
		if(p==l->frente)
		{
			l->frente=p->atras;
			if(p->atras!=NULL)
			{
			 p->atras->adelante=NULL;
			}
			free(p);
		}
		//Si P es el ultimo nodo
		else if(p==l->final)
		{
			l->final=p->adelante;
			p->adelante->atras=NULL;
			free(p);			
		}
		else
		{
			p->adelante->atras=p->atras;
			p->atras->adelante=p->adelante;
			free(p);			
		}
		//Actualizar el numero de nodos
		l->tam--;	
	}
	else
	{
		exit(1);
	}
}


/*
void Replace (lista * l, posicion p, elemento e);
Descripción: Recibe una lista y reemplaza al elemento dado por aquel que se encuentra en la posición dada.
Recibe: lista * l (Referencia a la lista "l"), posicion p (Referencia a la posición "p") y
elemento e (Referencia a la elemento "e").
Devuelve: 
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada.La 
posición dada es válida de lo contrario el programa terminará.
*/
void Replace(lista *l,posicion p, elemento e)
{
	//Validar la posicion
	if(ValidatePosition(l,p)==TRUE)
	{
		p->e=e;
	}
	else
	{
		exit(1);
	}	
}


//Operaciones de posicionamiento y busqueda


/*
posicion Final(lista * l);
Descripción: Recibe una lista y devuelve la posición del elemento que se encuentra al final de esta.
Recibe: lista * l (Referencia a la lista "l").
Devuelve: la posición del elemento del final de la lista.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada, esta 
deberá tener elementos de lo contrario devolvera ERROR. *No se modifica el TAD.
*/
posicion Final(lista *l)
{
	return l->final;
}


/*
posicion First (lista * l);
Descripción: Recibe una lista y devuelve la posición del elemento que se encuentra al principio de esta.
Recibe: lista * l (Referencia a la lista "l").
Devuelve: la posición del elemento al inicio de la lista.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada, esta 
deberá tener elementos de lo contrario devolverá ERROR. *No se modifica el TAD.
*/
posicion First(lista *l)
{
	return l->frente;
}


/*
posicion Following (lista * l, posicion p);
Descripción: Recibe una lista y devuelve la posición del elemento que se encuentra después de
la posición dada.
Recibe: lista * l (Referencia a la lista "l") y posicion p (Referencia a la posición "p").
Devuelve: la posición del elemento que se encuentra después de la posición dada.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada, esta 
deberá tener elementos de lo contrario devolverá ERROR. *No se modifica el TAD.
*/
posicion Following(lista *l, posicion p)
{
	if(ValidatePosition(l,p)==TRUE)
	{
		return p->atras;
	}	
	else
	{
		exit(1);
	}
}


/*
posicion Previous (lista * l, posicion p);
Descripción: Recibe una lista y devuelve la posición del elemento que se encuentra antes de
la posición dada.
Recibe: lista * l (Referencia a la lista "l") y posicion p (Referencia a la posición "p").
Devuelve: la posición del elemento que se encuentra antes de la posición dada.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada, esta 
deberá tener elementos de lo contrario devolverá ERROR. *No se modifica el TAD.
*/
posicion Previous(lista *l, posicion p)
{
	if(ValidatePosition(l,p)==TRUE)
	{
		return p->adelante;
	}	
	else
	{
		exit(1);
	}	
}


/*
elemento Search (lista * l, elemento e);
Descripción: Recibe una lista y devuelve la posición que le corresponde al elemento dado.
Recibe: lista * l (Referencia a la lista "l") y elemento e (Referencia a la elemento "e").
Devuelve: la posición que le corresponde al elemento dado.
Observaciones: El usuario ha creado una lista, la lista fue correctamente inicializada, el
elemento dado es válido de lo contrario el programa devolverá un NULL. *No se modifica el TAD.
*/
posicion Search(lista *l, elemento e)
{
	nodo *aux;
	aux=l->frente;
	while(aux!=NULL)
	{
		if(memcmp(&((*aux).e),&e,sizeof(elemento))==0) //memcmp(&aux->e,&e,sizeof(elemento)==0)
		{
			return aux;
		}
		aux=aux->atras;

	}
	return NULL;
}

