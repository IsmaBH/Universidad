#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADHash.h"

void
Cargar_archivo (tabla_hash * t, char *ruta_a_leer)
{
  int i;
  char p[50];
  char d[250];
  char *temp;
  char linea[500];
  int clave;
  FILE *archivo = 0;
  elemento e1;
  archivo = fopen (ruta_a_leer, "r");

  while ((i = leecad_archivo (linea, 500, archivo)) == 1)
    {
      temp = strtok (linea, ":");
      if (*temp != '\r')
	{
	  strcpy (p, temp);
	  //printf ("%s\n", p);
	  temp = strtok (NULL, ":");
	  strcpy (d, temp);
	  //printf ("%s\n", d);
	  clave = Hash (p);
	  strcpy (e1.p, p);
	  strcpy (e1.d, d);
	  AddInHash (t, e1, clave);
	}
    }
  fclose (archivo);
}


void
InitializeHash (tabla_hash * t)
{
  int n = TAM;
  while (n--)
    {
      Initialize (&t->nivel[n]);
    }
  return;
}


void
DestroyHash (tabla_hash * t)
{
  int n = TAM;
  while (n--)
    {
      Destroy (&t->nivel[n]);
    }
  return;
}


int
Hash (char *p)
{
  int i = 0;
  int valor = 0;
  while (p[i] != '\0')
    {
      valor = valor + (int) p[i];
      i++;
    }
  return valor % TAM;
}

void
AddInHash (tabla_hash * t, elemento e, int clave)
{
  Add (&t->nivel[clave], e);
  return;
}


posicion
SearchInHash(tabla_hash *t, char *p, int* contador)
{
  int clave = Hash (p);
  posicion principio;
  posicion final;
  principio = First (&t->nivel[clave]);
  final = Final (&t->nivel[clave]);
  elemento e2 = { };
  nodo *aux;

  if (Size (&t->nivel[clave]) == 1)
    {
      e2 = Position (&t->nivel[clave], principio);
      if (strcmp (e2.p, p) == 0)
	{
	  aux = principio;
	 *contador = *contador +1;
          return aux;
	}
    }
  else
    {
      while (final != NULL && principio != NULL && final != principio)
	{
	  e2 = Position (&t->nivel[clave], principio);
	  if (strcmp (e2.p, p) == 0)
	    {
	      aux = principio;
	      return aux;
	    }
	  else
	    {
	      principio = Following (&t->nivel[clave], principio);
	      *contador = *contador + 1;
	    }
	  e2 = Position (&t->nivel[clave], final);
	  if (strcmp (e2.p, p) == 0)
	    {
	      aux = final;
	      return aux;
	    }
	  else
	    {
	      final = Previous (&t->nivel[clave], final);
	      *contador = *contador +1;
	    }
	}
    }
  return NULL;
}


void 
DeleteInHash (tabla_hash *t, char *p, int* contador)
{

 int clave = Hash (p);
 posicion aux; 
 aux = SearchInHash (t, p, contador);
 Remove (&t->nivel[clave], aux);

}


void ReplaceInHash (tabla_hash *t, char *p, elemento e1, int* contador)
{
 posicion aux;
 elemento e2; 
 int clave = Hash(p);
 aux = SearchInHash (t, p, contador);
 Replace(&t->nivel[clave], aux, e1);
 e2 = Position(&t->nivel[clave], aux);
 printf ("\n%s", e2.d);
}


void Stats (tabla_hash *t, char* p)
{
  int clave = Hash (p);
  int colisiones = 0;
  colisiones = Size (&t->nivel[clave]);
  printf ("Las colisiones en esta lista son de: %d\n", colisiones);
  return;
}


int leecad_archivo(char *cad, int n, FILE *archivo) {
    int i, c;

    c=fgetc(archivo);
    if (c == EOF) {
        cad[0] = '\0';
	return 0;
    }

    if (c == '\n')
        i = 0;
    else {
        cad[0] = c;
        i = 1;
    }

    for (; i < n-1 && (c=fgetc(archivo))!=EOF && c!='\n'; i++)
       cad[i] = c;

    cad[i] = '\0';

    if (c != '\n' && c != EOF)
        while ((c = fgetc(archivo)) != '\n' && c != EOF);
	
    return 1;
}


void leecad(char *cad, int n) {
    int i, c;

    c=getchar();
    if (c == EOF) {
        cad[0] = '\0';
    }

    if (c == '\n')
        i = 0;
    else {
        cad[0] = c;
        i = 1;
    }

    for (; i < n-1 && (c=getchar())!=EOF && c!='\n'; i++)
       cad[i] = c;

    cad[i] = '\0';

    if (c != '\n' && c != EOF)
        while ((c = getchar()) != '\n' && c != EOF);

}
