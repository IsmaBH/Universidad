#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADHash.h"


int
main (void)
{
  //int i = 0;
  int contador = 0;
  int m = 0;
  int key = 0;
  int opc_interna = 0;
  char p[50];
  char nd[250];
  char nombre_archivo[250];
  elemento E;
  tabla_hash tabla[TAM];
  //posicion item;

  InitializeHash (tabla);
  while (m == 0)
    {
      printf ("\n\n\t\tMenu\n\n");
      printf ("[1] Cargar palabras del archivo\n");
      printf ("[2] Ingresar una nueva palabra y su definición\n");
      printf ("[3] Cambiar la definición de una palabra\n");
      printf ("[4] Buscar/Borrar una palabra\n");
      printf ("[5] Salir");
      printf ("\n\nSeleccione una opción: ");
      scanf ("%d", &m);
      switch (m)
	{
	case 0:
	  m = 0;
	  break;

	case 1:
	  //system("CLS");          
	  m = 0;
	  printf
	    ("\n\nIngrese el nombre del archivo acompañado de su extensión: ");
	  leecad (nombre_archivo, 250);
	  Cargar_archivo (tabla, nombre_archivo);
	  break;

	case 2:
	  //system("CLS");
	  m = 0;
	  printf ("Ingresa una nueva palabra: ");
	  scanf ("%s[^\n]", E.p);
	  printf ("Ingrese su definición: ");
	  leecad (nd, 250);
	  strcpy (E.d, nd);
	  key = Hash (E.p);
	  printf ("\n");
	  Stats (tabla, E.p);
	  printf ("El resultado de la función hash para la palabra es: %d", key);
	  AddInHash (tabla, E, key);
	  break;

	case 3:
	  m = 0;
	  printf ("Ingresa la palabra la cual quieres cambiar: ");
	  scanf ("%s[^\n]", p);
	  if (SearchInHash (tabla, p, &contador) != NULL)
	    {
              contador = 0;
	      E = SearchInHash (tabla, p, &contador)->e;
	      printf ("Se encontró la palabra\n\n");
	      key = Hash (p);
	      Stats (tabla, p);
	      printf ("El resultado de la función hash para la palabra es: %d", key);
	      printf ("\nSe encontró en %d saltos\n", contador);
	      printf ("Su definicion es: %s", E.d);
	      printf ("\n\nIngresa la nueva definición: ");
	      leecad (nd, 250);
	      strcpy (E.d, nd);
	      ReplaceInHash (tabla, p, E, &contador);
	    }
	  else
	    {
	      printf
		("\n\nLa palabra tecleada no está en el archivo de definiciones\n");
	    }
	  break;

	case 4:
	  //system("CLS");
	  m = 0;
	  printf ("Busca una palabra: ");
	  scanf ("%s[^\n]", p);
	  if (SearchInHash (tabla, p, &contador) != NULL)
	    {
	      printf ("Se encontró la palabra\n\n");
	      key = Hash (p);
	      Stats (tabla, p);
	      printf ("El resultado de la función hash para la palabra es: %d", key);
              contador = 0;
	      E = SearchInHash (tabla, p, &contador)->e;
	      printf ("\nSe encontró en %d saltos\n", contador);
	      printf ("\nSu definición es: %s", E.d);
	      printf ("\n\n¿Borrar palabra?\n1.Sí\n2.No");
	      printf ("\nElija una opción: ");
	      scanf ("%d", &opc_interna);
	      switch (opc_interna)
		{
		case 1:
		  DeleteInHash (tabla, p, &contador);
		  printf ("\nSe eliminó correctamente la palabra\n");
		  break;

		case 2:
		  printf ("\nPalabra conservada\n");
		  break;
		}
	    }
	  else
	    {
	      printf
		("\n\nLa palabra tecleada no está en el archivo de definiciones\n");
	    }
	  break;

	case 5:
	  //system("CLS");
	  printf ("\n\nUsted ha salido del programa\n\n");
	  m++;
	  break;

	default:
	  //system("CLS"); 
	  printf ("\nOpción incorrecta");
	  m = 0;
	  break;
	}
    }

  return 0;
}
