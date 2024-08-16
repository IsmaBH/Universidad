/*
  AUTOR: BARON HERNANDEZ DIEGO ISMAEL
  COMPILACION: Compilado en Ubuntu 14.04 (LINUX) y ejecutable en cualquier sistema operativo excepto IOS, esta compilado bajo el estandar
  OBSERVACIONES: Este programa acepta hasta un maximo de 1000 empleados pero tiene un  defecto que no pude corregir, durante el primer registro
                 captura correctamente a los empleados, pero a la hora de hacer el ordenamiento, empieza a hacer cosas rarar.
  LIBRERIAS: stdio.h que es del estandar y la libreria propia llamada funciones.h
*/
#include <stdio.h>
#include "funciones.h"

struct empleado
{
  int no_empleado;
  char nombre[45];
  char departamento[45];
  float salario;
  char domicilio[100];
};

int main (void)
{
  int opcion = 0;
  int numero_contactos = 0;
  int x = 0;
  struct empleado agenda[1000];
  FILE *fp=0;
     numero_contactos = rellenar (agenda);
      while(opcion!=4)
           {
            x = 0;
          while(x <= numero_contactos)
          {  
            ordenar_agenda (agenda, numero_contactos);
            x++;
          }
            opcion = mostrar_menu();
            switch(opcion)
                   {
                     case 1: 
                     numero_contactos = agregar_contacto(agenda, numero_contactos);//mando a llamar la funcion que agrega contactos
                     break;
                     case 2: 
                     numero_contactos = eliminar_registro(agenda, numero_contactos);
                     break;
                     case 3:
                     mostrar_agenda(agenda, numero_contactos);//muestro la agenda 
                     break;
                     case 4:printf("Adios \n");
                     break;
                     default: printf("Ingresa un numero \n");//Por si no ingresa un numero el usuaro le mando que lo meta >:v
                     break;
                   }
 }
 return 0;
}

