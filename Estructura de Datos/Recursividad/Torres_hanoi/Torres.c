/*
	24/01/2012

	Escribe un programa (se recomienda que sea recursivo) que dé solución al problema de las torres de Hanoi.
	El enunciado es el siguiente: Se dispone de una torre formada por varios discos de diferentes diámetros denominada torre O (origen),
	donde cada disco es de diámetro inferior a todos los que están por debajo. Se dispone de otras dos torres para dejar discos, una denominada torre A (auxiliar) y otra torre D (destino).
	El problema consiste en pasar todos los discos de la torre O a la torre D respetando dos normas muy simples:

	Los discos se pasan de una torre a otra de uno en uno.
	Nunca un disco de mayor diámetro puede estar sobre otro de menor diámetro.
	Se preguntará al inicio del programa por el tamaño de la torre O (entendiendo que tendrá el número de discos indicados, con algún límite preestablecido).
	Las torres A y D estarán inicialmente vacías.
	Se debe ofrecer la solución que da el programa a este problema paso a paso, mostrando el resultado de una forma gráfica. El inicio podría ser algo así:

			*
		   ***
		  *****
		 *******
		*********
	   ===========		==========		==========
		 Inicio		     Auxiliar		 Destino
*/
/*
	Formula para calcular movimientos mínimos necesarios:
	m = 2^n -1

*/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "presentacionWin.c"

void imprime( int *Matrix, int fil, int col, int Gnum )
{
	/*
	Precondición:
					*Matrix	Puntero a una matriz de tipo entero.
					fil		Entero que indica el numero de filas de la matriz.
					col		Entero que indica el numero de columnas de la matriz.
					disc	Parámetro de tipo entero que indica el numero de discos usados.
					Gnum	Entero que indica el numero que esta usando el disco mas grande.
*/


	int F,C ;
	int i, espacios;

printf("\n");
	for( C=col-1; C >= 0; C-- )
	{
		for( F=0; F < fil; F++ )
		{
			espacios = ( Gnum - Matrix[col*F+C] )/2;
        
			// Espacios a la izquierda
			for( i=0; i < espacios; i++ )
				printf( " " );

			// Imprime los *
			for( i=0; i < Matrix[col*F+C]; i++ )
				printf( "%c",223 );

			// Espacios a la derecha	
			for( i=0; i < espacios; i++ )
				printf( " " );
				
				printf( "\t" );
		};

		printf( "\n" );
	};


};


void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )
{
	/*
	Precondición:
					*tab	Puntero a una matriz de tipo entero.
					fil		Entero que indica el numero de filas de la matriz.
					col		Entero que indica el numero de columnas de la matriz.
					disc	Parámetro de tipo entero que indica el numero de discos usados.
					ultNum	Entero que indica el numero que esta usando el disco mas grande.
					filOrig	Entero que indica el numero de fila de la matriz en la cual hay que coger el numero/disco
					filDest	Entero que indica el numero de fila de la matriz en la cual hay que dejar el numero/disco.
	Poscondición:
					Se mueve el disco y se llama a la función que imprime el tablero.
	*/


	int cO=col-1, cD=col-1;


	// Se busca el disco que se encuentre mas arriba y por lo tanto el mas pequeño de la fila de origen.
	while( cO >= 0  &&  tab[col*filOrig+cO] == 0 )
	{
		cO--;
	};
	if( cO < 0 )
		cO = 0;

	// Ahora se calcula cual es la posición libre mas arriba de la fila de destino
	while( cD >= 0  &&  tab[col*filDest+cD] == 0 )
	{
		cD--;
	};

	// Se mueve el disco de la fila de origen a la de destino:
	tab[col*filDest+cD+1] = tab[col*filOrig+cO];
	tab[col*filOrig+cO] = 0;

	// Se imprime el tablero:
	imprime( tab, fil, col, ultNum );
};


void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )
{
/*
Precondición:
				*tab	Puntero a una matriz de tipo entero.
				fil		Entero que indica el numero de filas de la matriz.
				col		Entero que indica el numero de columnas de la matriz.
				disc	Parámetro de tipo entero que indica el numero de discos usados.
				ultNum	Entero que indica el numero que esta usando el disco mas grande.
				O,A,D	Tres enteros que indican la fila desde donde se ha de coger el disco y a donde se ha de traspasar. La primera vez que se llama a hanoi tienen los valores de: 0 ,1 y 2 respectivamente.
Poscondición:
				Se llama recursivamente a hanoi hasta resolver el tablero.
*/


	if( disc==1 )
	{
		// Se borra la pantalla, se imprime la tabla y se hace una pausa que varia dependiendo del numero de discos:
		system("CLS");
		Imp_Titulo();
		mueveDisco( tab, fil, col, ultNum, O, D );
		if(col<=5)  Sleep(800); else if(col<=10) Sleep(300); else if(col<=15) Sleep(600); else if(col>15)Sleep(200);
	}
	else
	{
		hanoi( tab, fil, col, disc-1, ultNum, O, D, A );

	system("CLS");
	Imp_Titulo();
		mueveDisco( tab, fil, col, ultNum, O, D );
		if(col<=5) Sleep(800); else if(col<=10) Sleep(300); else if(col<=15) Sleep(600); else if(col>15) Sleep(200);

		hanoi( tab, fil, col, disc-1, ultNum, A, O, D );
	};

};


main()
{
	int fil=3, col, *tablero = NULL;
	int f, c, disc=1, ultNum;
	
	Imp_Titulo();
	
	printf( "\n\nIndique el numero de discos: " );
	scanf( "%i", &col );


	tablero = (int *)malloc( sizeof(int)*fil*col );


	// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
	for( f=0; f < fil; f++ )
		for( c=col-1; c >= 0; c-- )
			if( f==0 )
			{
				tablero[col*f+c] = disc;
				disc+=2;
			}
			else
				tablero[col*f+c] = 0;

	ultNum = disc;

	// Se imprime el tablero antes de iniciar ningún movimiento:
	system("CLS");
	Imp_Titulo();
	printf("\n\n");
	imprime( tablero, fil, col, ultNum );
	Sleep(1000);


	// Se llama a hanoi para comenzar "la partida":
	printf("\n\n");
	hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 );
};




void Imp_Titulo()
{
	
	int q;
	for(q=0;q<150;q++)
{
	
	if(q>-1&&q<9)
   {
	MoverCursor(8,q);
	printf("//");
	MoverCursor(107,q);
    printf("//");
   }
   
    if(q>8&&q<108)
	{
		MoverCursor(q,0);
    	printf("//");
    	MoverCursor(q,8);
    	printf("//");	
    }
    
    
    
    
    
    //T
    if(q>11&&q<17)
	{
       MoverCursor(q,2);
       printf("||");
     if(q==14) 
	 {
	  MoverCursor(q,3);
      printf("||");
      MoverCursor(q,4);
      printf("||");
      MoverCursor(q,5);
      printf("||");
      MoverCursor(q,6);
      printf("||");
     }
     
     
     //O
     MoverCursor(q+8,2);
     printf("||");
        if(q==14){
       	MoverCursor(q+6,3);
       	printf("||");
       	MoverCursor(q+6,4);
       	printf("||");
       	MoverCursor(q+6,5);
       	printf("||");
       	MoverCursor(q+6,6);
       	printf("||");
       	MoverCursor(q+10,3);
       	printf("||");
       	MoverCursor(q+10,4);
       	printf("||");
       	MoverCursor(q+10,5);
       	printf("||");
       	MoverCursor(q+10,6);
       	printf("||");
       	MoverCursor(q+8,6);
       	printf("||");
	   }
       
       
       //R
	   MoverCursor(q+16,2);
       printf("||");
	   if(q==14){
       	MoverCursor(q+14,3);
       	printf("||");
       	MoverCursor(q+14,4);
       	printf("||");
       	MoverCursor(q+14,5);
       	printf("||");
       	MoverCursor(q+14,6);
       	printf("||");
       	MoverCursor(q+10,3);
       	printf("||");
       	MoverCursor(q+16,4);
       	printf("||");
       	MoverCursor(q+18,3);
       	printf("||");
       	MoverCursor(q+18,4);
       	printf("||");
       	MoverCursor(q+17,5);
       	printf("||");
       	MoverCursor(q+18,6);
       	printf("||");
       	MoverCursor(q+10,6);
       	printf("||");
       	MoverCursor(q+8,6);
       	printf("||");
	   } 
       
       
       
       
       
       //R
	   MoverCursor(q+24,2);
       printf("||");
       if(q==14){
       	MoverCursor(q+22,3);
       	printf("||");
       	MoverCursor(q+22,4);
       	printf("||");
       	MoverCursor(q+22,5);
       	printf("||");
       	MoverCursor(q+22,6);
       	printf("||");
       	MoverCursor(q+18,3);
       	printf("||");
       	MoverCursor(q+24,4);
       	printf("||");
       	MoverCursor(q+26,3);
       	printf("||");
       	MoverCursor(q+26,4);
       	printf("||");
       	MoverCursor(q+25,5);
       	printf("||");
       	MoverCursor(q+26,6);
       	printf("||");
	   } 
       
	   
	   
	   //E 
	   MoverCursor(q+32,2);
       printf("||");
       if(q==14){
       MoverCursor(q+30,3);
       printf("||");
       MoverCursor(q+30,4);
       printf("||");
       MoverCursor(q+31,4);
       printf("||");
       MoverCursor(q+32,4);
       printf("||");
        MoverCursor(q+31,6);
       printf("||");
       MoverCursor(q+32,6);
       printf("||");
        MoverCursor(q+33,6);
       printf("||");
       MoverCursor(q+34,6);
       printf("||");
       MoverCursor(q+30,5);
       printf("||");
       MoverCursor(q+30,6);
       printf("||");
	   } 
	   
	   
       
       
       //S
	   MoverCursor(q+40,2);
       printf("||"); 
       if(q==14)
	   {
       MoverCursor(q+38,3);
       printf("||"); 
       MoverCursor(q+38,4);
       printf("||||||"); 
       MoverCursor(q+42,5);
       printf("||"); 
       MoverCursor(q+38,6);
       printf("||||||"); 
	   } 
	   
       
       
       
       
       //H
	   
       if(q==14)
	   {
	   	MoverCursor(q+54,2);
       printf("||  ||");
       MoverCursor(q+54,6);
       printf("||  ||");
       MoverCursor(q+56,4);
       printf("||||");
	   MoverCursor(q+58,3);
       printf("||");
       MoverCursor(q+58,5);
       printf("||");
       MoverCursor(q+54,3);
       printf("||"); 
       MoverCursor(q+54,4);
       printf("||");
	   MoverCursor(q+54,5);
       printf("||");  
       MoverCursor(q+54,6);
       printf("||"); 
	   } 
	   
       
       //A
	   MoverCursor(q+64,2);
       printf("||");
       if(q==14)
	   {
	   	MoverCursor(q+64,4);
       printf("||");
       	MoverCursor(q+62,4);
       printf("||");
	   	MoverCursor(q+66,4);
       printf("||");
       MoverCursor(q+66,3);
       printf("||");
       MoverCursor(q+66,5);
       printf("||");
       MoverCursor(q+66,6);
       printf("||");
       MoverCursor(q+62,3);
       printf("||");
       MoverCursor(q+62,5);
       printf("||");
       MoverCursor(q+62,6);
       printf("||");
	   } 
       
       
       //N
	   
       if(q==14)
	   {
	   	MoverCursor(q+70,2);
       printf("||  ||");
       MoverCursor(q+72,3);
       printf("|");
       MoverCursor(q+73,4);
       printf("|");
       MoverCursor(q+74,5);
       printf("|");
	   	MoverCursor(q+70,4);
       printf("||");
       	MoverCursor(q+70,3);
       printf("||");
	   	MoverCursor(q+70,5);
       printf("||");
       MoverCursor(q+70,6);
       printf("||");
       MoverCursor(q+74,5);
       printf("||");
       MoverCursor(q+74,4);
       printf("||");
       MoverCursor(q+74,3);
       printf("||");
       MoverCursor(q+74,6);
       printf("||");
       
	   } 
       
       
	   MoverCursor(q+80,2);
       printf("||");
	      if(q==14)
	   {
	   	MoverCursor(q+78,3);
       printf("||  ||");
       MoverCursor(q+78,4);
       printf("||  ||");
       MoverCursor(q+78,5);
       printf("||  ||");
       MoverCursor(q+78,6);
       printf("||||||");
	   }  
       
       
       //I
	   MoverCursor(q+88,2);
       printf("||"); 
	      if(q==14)
	   {
	   	MoverCursor(q+88,3);
       printf("||");
       MoverCursor(q+88,4);
       printf("||");
       MoverCursor(q+88,5);
       printf("||");
       MoverCursor(q+86,6);
       printf("||||||");
       
       
	   }             	
	}
    
    
    
}
}









