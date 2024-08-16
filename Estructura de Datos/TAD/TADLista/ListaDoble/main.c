#include "TADListaD.h"
#include <stdio.h>
#include <string.h>
#define NUM_LISTAS 2

int main (void)
{
	lista L[NUM_LISTAS];
	elemento e1,e2;
	posicion p1,p2,p3;
	int i;
	
	//Inicializar las listas
	for(i=0;i<NUM_LISTAS;i++)
	{
		Initialize(&L[i]);
	}
	
	
	//Capturar 10 nombres L[0]
	for (i=0;i<10;i++)
	{
		scanf("%s",e1.nombre);
		Add(&L[0],e1);
	}
	
	p1=First(&L[0]);
	printf("\nLista 1:");
	//Mostra las lista al reves L[0]
	for (i=1;i<=Size(&L[0]);i++)
	{
		e1=Position(&L[0],p1);
		printf("\t%s",e1.nombre);
		p1=Following(&L[0],p1);
	}
	
	
	strcpy(e1.nombre,"Edgardo");
	p2=Search(&L[0],e1);
	if(ValidatePosition(&L[0],p2))
	{
		e2=Position(&L[0],p2);	
		printf("\n%s Si lo encontre",e2.nombre);
		p3=Following(&L[0],p2);
		Remove(&L[0],p2);
		strcpy(e1.nombre,"Adrian");
		Insert(&L[0],e1,p3,TRUE);
		p3=Search(&L[0],e1);
		strcpy(e1.nombre,"Franco");
		Replace(&L[0],p3,e1);
	}
	
	p1=First(&L[0]);
	printf("\nLista 2: ");
	//Mostra las lista al reves L[0]
	for (i=0;i<11&&ValidatePosition(&L[0],p1);i++)
	{
		e1=Position(&L[0],p1);
		printf("\t%s",e1.nombre);
		p1=Following(&L[0],p1);
	}
	
	printf("\nTam=%lu",Size(&L[0]));
	
	e2=Element(&L[0],10);
	printf("\nElemento 10=%s",e2.nombre);
	
	//Destruir las listas
	for(i=0;i<NUM_LISTAS;i++)
	{
		Destroy(&L[i]);
	}
	
	
	
	printf("\nTermine Adios");
	return 0;
}

