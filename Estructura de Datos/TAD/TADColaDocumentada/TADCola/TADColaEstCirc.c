/*
IMPLEMENTACION DE LA LIBRERIA DEL TAD COLA ESTATICA (TADColaEst.h) *DE MANERA CIRCULAR
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2013
VERSIÓN: 1.4

DESCRIPCIÓN: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y 
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos estática cuando 
se le asigna una cantidad fija de memoria para esa estructura 
antes de la ejecución del programa. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADColaEstCirc.c
*/

//LIBRERAS
#include "TADColaEst.h"

//DEFINICIÓN DE FUNCIONES

/*
void Initialize(cola *c);
Descripción: Inicializar cola (Iniciar una cola para su uso)
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: El usuario a creado una cola y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(cola * c)
{
	c->frente = -1;
	c->final = -1;
	c->num_elem=0;
	return;
}

/*
void Queue(cola * c, elemento e);
Descripción: Recibe una cola y agrega un elemento al final de ella.
Recibe: cola *c (Referencia a la cola "c" a operar) elemento e (Elemento a encolar)
Devuelve:
Observaciones: El usuario a creado una cola y ha sido inicializada y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error. *Manejo de manera circular.
*/
void Queue(cola * c, elemento e)
{
	int a=0;	//Marcado para saber que la cola se ha inicializado
	//Si la cola esta vacia
	if (c->frente == -1 && c-> final == -1)
	{
		//Incrementar el subindice del frente
		c->frente++;
		a=1;
	}
	//Incrementar el subindice del final de la cola
	c->final++;
	
	//Si el final alcanza el tamaño maximo regresarlo a 0
	if(c->final==MAX_ELEMENT)
	{
		c->final=0;
	}
	//Si el final es igual al frente y no ha sido inicializada .:. la cola se ha llenado
	if(c->final==c->frente&&a!=1)
	{
		printf("\nERROR:Desbordamiento de la cola");
		exit (1);
	}
	
	//Introducir el elemento en el subindice final del arreglo
	c->elementos[c->final] = e;
	
	//Incrementar el número de elementos en la cola
	c->num_elem++;
	
	return;
}

/*
elemento Dequeue(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al 
frente de esta, quitándolo de la cola.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve: elemento (Elemento desencolado)
Observaciones: El usuario a creado una cola y la cola tiene elementos, si no 
se genera un error y se termina el programa. *Manejo de manera circular
*/
elemento Dequeue(cola * c)
{
	elemento e;//Elemento a retornar
	e = c->elementos[c->frente];//Almacenar el elemento a retornar
	
	//Incrementar el subindice del frente de la cola
	c->frente++;
	
	//Si el frente alcanza el tamaño maximo regresarlo a 0
	if(c->frente>=MAX_ELEMENT)
	{
		c->frente=0;	
	}
	
	//Si el nuevo frente y el final + 1 son iguales, la cola ha quedado vacia
	if((c->frente)==(c->final+1))
	{
		c->frente=-1;
		c->final=-1;
	}
	
	//Decrementar el número de elementos en la cola
	c->num_elem--;
	
	//Retornar al elemento desencolado
	return e;
}

/*
boolean Empty(cola * c);
Descripción: Recibe una cola y TRUE si la cola esta vacia y FALSE en caso contrario
Recibe: cola *c (Referencia a la cola "c" a verificar)
Devuelve: boolean TRUE O FALSE
Observaciones: El usuario a creado una cola y la cola fue correctamente inicializada
*/
boolean Empty(cola * c)
{
	return (c->frente == -1 && c->final == -1) ? TRUE : FALSE; //Instrucción simplificada con el operador ?
}

/*
elemento Front(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al frente de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del frente de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Front(cola * c)
{
	return c->elementos[c->frente];
}

/*
elemento Final(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al final de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del final de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Final(cola * c)
{
	return c->elementos[c->final];
}

/*
int Size(cola * c);
Descripción: Recibe una cola y devuelve el número de elemento que se encuentran en esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: int (Tamaño de la cola)
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
*No se modifica el TAD
*/
int Size(cola * c)
{
	return c->num_elem;
}

/*
void Destroy(cola * c);
Descripción: Recibe una cola y la libera completamente.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: La cola se destruye y se inicializa.
*/
void Destroy(cola * c)
{
	c->frente = c->final = -1;
	c->num_elem=0;
}
