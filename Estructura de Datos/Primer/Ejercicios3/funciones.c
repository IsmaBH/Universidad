#include <stdio.h>
#include <string.h>
#include "funciones.h"

struct empleado{
int no_empleado;
char nombre[45];
char departamento[45];
float salario;
char domicilio[100];
int eliminado;
};

int mostrar_menu(void)//solo printfs que muestran el menu y ya
    {
    	int opcion = 0;
    	printf("1) Capturar empleado \n");
    	printf("2) Eliminar empleado \n");
    	printf("3) Ver registro \n");
    	printf("4) Salir \n");
    	scanf("%d",&opcion);//escaneo la opcion que eligio el usuario
    	return opcion;//regreso la opcion
    }
int agregar_contacto (struct empleado *agenda, int numero_contactos)//Funcion para nuevos contactos
{
    int i=0;
    i = numero_contactos;
    FILE *fp=0;
    fp = fopen("empleados.csv","a");// Ojo al dato, abro el archivo en modo "a", que es para escribir hasta la parte inferior del mismo
	int no_empleado = 0;
        char nombre[45];
        char departamento[45];
	float salario = 0.0f;
        char domicilio[100];
        int no_empleado2 = 0;
        int x = 0;
	printf ("No. de empleado \n");
	scanf ("%d", &agenda[i].no_empleado);
	printf ("Nombre: \n");
	scanf ("%s",agenda[i].nombre);
        printf ("Departamento:\n");
        scanf ("%s",agenda[i].departamento);
        printf ("Salario:\n");
        scanf ("%f", &agenda[i].salario);
        printf ("Domicilio:\n");
        scanf ("%s", agenda[i].domicilio);
     
	while(x < numero_contactos)
      	{
       	no_empleado2 = (agenda+x)->no_empleado;
       	x++;
        /*if(no_empleado == no_empleado2)
       	 {
      	  printf("Ingresa otro numero de empleado \n");
 	  scanf("%d",&no_empleado);
 	 }*/
 	}
       for (i = 0; i < numero_contactos; i++)
        {
        fprintf(fp,"%d", agenda[i].no_empleado);
	fprintf(fp,", ");
	fprintf(fp,"%s",agenda[i].nombre);
	fprintf(fp,", ");
        fprintf(fp,"%s",agenda[i].departamento);
	fprintf(fp,", ");
        fprintf(fp, "%f",agenda[i].salario);
	fprintf(fp,", ");
        fprintf(fp,"%s",agenda[i].domicilio);
        fprintf(fp," \n");
        }
	fclose(fp);
	numero_contactos++;
	return numero_contactos;
}

int rellenar (struct empleado *agenda)//esta funcion llena la agenda a partir de un archivo txt
    {
      FILE *fp=0;
      fp = fopen ("empleados.csv","r");//abro la direccion del archivo en modo "r"  que es reading
      int i=0;
      int coma;
      int numero_contactos=0;
      while(!feof(fp))//mientras el archivo tena algo, sigo revisandolo
      	    {
             fscanf(fp,"%d, ",&(agenda+i)->no_empleado);
             fscanf(fp,"%s, ",(agenda+i)->nombre);//La coma la incluye a la cadena
             coma = strlen((agenda+i)->nombre);
             coma = coma-1;
             *((agenda+i)->nombre+coma) = '\0'; 
             fscanf(fp,"%s",(agenda+i)->departamento);
             fscanf(fp,"%f",&(agenda+i)->salario);
             fscanf(fp,"%s \n",(agenda+i)->domicilio);
             (agenda+i)->eliminado = 0;
             i++;
      	    }
      i=i-1;
      numero_contactos = (i);
      fclose(fp);
      return numero_contactos;//regreso el total contado, que en este caso se llama numero_contactos
    }
int ordenar_agenda (struct empleado *agenda, int numero_contactos){
int x=0;
int f=1;
int buffer=0;
int no_empleado = 0;
int no_empleado2 = 0;
 while(x < numero_contactos)
 {
  no_empleado = (agenda+x)->no_empleado;  
  no_empleado2 = (agenda+f)->no_empleado;
  if(no_empleado <= no_empleado2)
    {
    ordenar_contacto(agenda, f, x);
    }
  x++;
  f++;
 }
 buffer = sobreescribir_agenda(agenda, numero_contactos);//Mando a llamar la funcion que "guarda" los cambios realizados en el documento
}

int ordenar_contacto (struct empleado *agenda, int f, int x)//mando a llamar la funcion que hace el swap
{
 int no_empleado_temporal;
 char nombre_temporal[50];
 char departamento_temporal[50];
 float salario_temporal=0.0f;
 char domicilio_temporal[100];
 int i=0;
 i=x;
 // struct contacto temporal;//Declaro un temporal de tipo struct  
  no_empleado_temporal = (agenda+i)-> no_empleado;
  (agenda+i)->no_empleado = (agenda+f)-> no_empleado;
  (agenda+f)->no_empleado = no_empleado_temporal;
  
  strcpy(nombre_temporal, (agenda+i)->nombre);
  strcpy((agenda+i)->nombre, (agenda+f)->nombre);
  strcpy((agenda+f)->nombre, nombre_temporal);
  
  strcpy(departamento_temporal, (agenda+i)->departamento);
  strcpy((agenda+i)->departamento, (agenda+f)->departamento);
  strcpy((agenda+f)->departamento, departamento_temporal);

  salario_temporal = (agenda+i)->salario;
  (agenda+i)->salario = (agenda+f)->salario;
  (agenda+f)->salario = salario_temporal;
  
  strcpy(domicilio_temporal, (agenda+i)->domicilio);
  strcpy((agenda+i)->domicilio, (agenda+f)->domicilio);
  strcpy((agenda+f)->domicilio, domicilio_temporal);
  
return 0;
}

int sobreescribir_agenda (struct empleado *agenda, int numero_contactos)//Funcion que "guarda" los cambios
{
 int i=0;
 FILE *fp = fopen("empleados.csv", "w");//Mando a abrir el erchivo en modo "w" que es write, para escribir desde el inicio
 fclose(fp);
 remove("empleados.csv");//Borro el archivo
 fp = fopen("empleados.csv","w");//vuelvo a crear el archivo y comienzo a llenarlo con los datos ya en orden
 numero_contactos++;
 while(i < numero_contactos)// mientras "i", sea menor que el numero de contactos, sigo aumentando
          {
          if((agenda+i)->eliminado != 1)
 	  {
 	  	fprintf(fp,"%d, ",(agenda+i)->no_empleado);
                fprintf(fp,"%s, ",(agenda+i)->nombre);//Hago lo mismo que en la funcion agregar nuevo contacto
 	        fprintf(fp,"%s, ",(agenda+i)->departamento);
 	    	fprintf(fp,"%f, ",(agenda+i)->salario);
                fprintf(fp,"%s\n",(agenda+i)->domicilio);
        	}
      		i++;
 	  }
 fclose(fp);
 return 0;
}

int eliminar_registro(struct empleado *agenda, int numero_contactos)
{
 int no_empleado = 0;
 int no_empleado2 = 0;
 int x=0;
 int buffer=0;
 int encontrado = 0;
 printf("Ingresa el numero de empleado \n");
 scanf("%d",&no_empleado);
 while(x < numero_contactos)
      {
       no_empleado2 = (agenda+x)->no_empleado;
       if(no_empleado == no_empleado2)
         {
          (agenda+x)->eliminado = 1;
          encontrado = 1;
         }
       x++;
      }
 if(encontrado==1)
   {
    printf("Registro eliminado \n");
   }
 else
   {
    printf("Registro no encontrado \n");
   }
 buffer = sobreescribir_agenda(agenda, numero_contactos);
 numero_contactos--;
 buffer = rellenar(agenda);
 return numero_contactos;
}

void mostrar_agenda(struct empleado *agenda, int numero_contactos)// una funcion que muestra los contactos 
{
 int i = 0;
 for(i=0; i <= numero_contactos; i++)
    {
     printf("%d ",(agenda+i)->no_empleado);
     printf("%s ",(agenda+i)->nombre);
     printf("%s ",(agenda+i)->departamento);
     printf("%f ",(agenda+i)->salario);
     printf("%s \n",(agenda+i)->domicilio);
    }
}
