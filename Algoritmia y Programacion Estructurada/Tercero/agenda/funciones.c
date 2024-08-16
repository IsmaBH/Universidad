#include "funciones.h"

struct contacto
{
  char nombre[80];
  char telefono[11];
};

int mostrar_menu(void)
    {
    	int opcion =0;
    	printf("1) agregar \n");
    	printf("2) Leer archivo txt \n");
    	printf("3) mostrar \n");
    	printf("4) ordenar \n");
    	printf("5) salir \n");
    	scanf("%d",&opcion);
    	return opcion;
    }

int rellenar (struct contacto *agenda)
    {
      FILE *fp=0;
      fp = fopen ("agenda.txt","r");
      int i=0;
      int numero_contactos=0;
      while(!feof(fp))
      	    {
             fscanf(fp,"%s",(agenda+i)->nombre);
             fscanf(fp,"%s",(agenda+i)->telefono);
             i++;
      	    }
      numero_contactos = (i-1);
      fclose(fp);
      return numero_contactos;
    }

void mostrar_agenda(struct contacto *agenda, int numero_contactos)
{
 int i=0;
 for(i=0; i < numero_contactos; i++)
    {
     printf("%s \n",(agenda+i)->nombre);
     printf("%s \n",(agenda+i)->telefono);
    }
}

void agregar_contacto (void)
{
  int verificar=0;
  int basura=0;
  while(verificar!=2)
  	    {
  	    printf("1) Añadir nuevo contacto \n");
  	    printf("2) Terminar de capturar \n");
  	    scanf("%d",&verificar);
  	    switch(verificar)
  	    {
 		 case 1: verificar = nuevo_contacto();
  		 break;
  		 default: printf("Ingresa una opcion valida \n");
  		 break;
   		}
     	}
}

int nuevo_contacto (void)
{
    FILE *fp=0;
    fp = fopen("agenda.txt","a");
	char nombre[40];
	char telefono[10];
	printf("Ingresa el nombre \n");
	scanf("%s",nombre);
	printf("Ingresa el telefono \n");
	scanf("%s",telefono);
	fprintf(fp,"%s",nombre);
	fprintf(fp,"\n");
	fprintf(fp,"%s",telefono);
	fprintf(fp,"\n");
	fclose(fp);
	return 0;
}

int comparar_caracter (char caracter1, char caracter2)
{
 int resultado=0, resultado1=0, resultado2=0;
 if(caracter1>caracter2)
  {
   resultado1++;
  }
 if(caracter2>caracter1)
  {
   resultado2++;
  }
  if (resultado1 < resultado2)
     {
      resultado = 2;
     }
  if (resultado1 > resultado2)
  	 {
  	  resultado = 1;
  	 }
  if(resultado1 == resultado2)
  	 {
  	  resultado = 0;
  	 }
  return resultado;
}

int ordenar_agenda (struct contacto *agenda, int numero_contactos)
{
int x=0;
int buffer=0;
int opcion1=0;
int opcion2=0;
 printf("Quieres ordenar la agenda por nombre o telefono \n");
 printf("1) Nombre \n");
 printf("2) Telefono \n");
 scanf("%d",&opcion1);
 printf("Quieres ordenar de forma ascendente o descendente \n");
 printf("1) Ascendente \n");
 printf("2) Descendente \n");
 scanf("%d",&opcion2);
 while(x < numero_contactos)
 {
 buffer = comparar_cadena(agenda, numero_contactos, opcion1, opcion2); 
 x++;
 }
 buffer = sobreescribir_agenda(agenda, numero_contactos);
}

int sobreescribir_agenda (struct contacto *agenda, int numero_contactos)
{
 int i=0;
 FILE *fp = fopen("agenda.txt", "w");
 fclose(fp);
 remove("agenda.txt");
 fp = fopen("agenda.txt","w");
 while(i < numero_contactos)
 	  {
 	  	fprintf(fp,"%s",(agenda+i)->nombre);
 	  	fprintf(fp,"\n");
 	    fprintf(fp,"%s",(agenda+i)->telefono);
        fprintf(fp,"\n");
 	    i++;
 	  }
 fclose(fp);
 return 0;
}

int comparar_cadena (struct contacto *agenda, int numero_contactos, int opcion1, int opcion2)
{
 char *cadena1;
 char *cadena2;
 char caracter1;
 char caracter2;
 int resultado=0;
 int longitud=0;
 int i=0, r=0, f=1;
while(i < numero_contactos)
 {
 if (opcion1 == 1)
 {
 cadena1 = (agenda+i)->nombre;
 cadena2 = (agenda+f)->nombre;
 }
 if (opcion1 == 2)
 {
 cadena1 = (agenda+i)->telefono;
 cadena2 = (agenda+f)->telefono; 
 }
 resultado=0;
 r=0;
  while(resultado == 0 && *(cadena1+r) != '\0' && *(cadena2+r) != '\0')
  {
        caracter1=*(cadena1+r);
        caracter2=*(cadena2+r);
        resultado = comparar_caracter(caracter1, caracter2);
        r++;
  }
  longitud = strlen(cadena2);
  if(longitud > 0)
  {
  ordenar_contacto(agenda, resultado, f, i, opcion2);
  }
  i++;
  f++;
 }
 return 0;
}

int ordenar_contacto (struct contacto *agenda, int resultado, int f, int i, int opcion2)
{
 struct contacto temporal;
 if(resultado == 1 && opcion2 == 1)
 {
  temporal = *(agenda+i);
  *(agenda+i) = *(agenda+f);
  *(agenda+f) = temporal;
 }
  if(resultado == 2 && opcion2 == 2)
 {
  temporal = *(agenda+f);
  *(agenda+f) = *(agenda+i);
  *(agenda+i) = temporal;
 }
return 0;
}