#include "funciones.h"

struct contacto
{
  char nombre[80];
  char telefono[11];
};

int main (void)
{
  int opcion=0;
  int numero_contactos=0;
  struct contacto agenda[100];
  FILE *fp=0;
      while(opcion!=5)
      	   {
            opcion=mostrar_menu();
            switch(opcion)
                   {
                   	 case 1: 
                   	 agregar_contacto();
                   	 break;
                   	 case 2: 
                   	 numero_contactos = rellenar(agenda);
                   	 break;
                   	 case 3: 
                   	 mostrar_agenda(agenda, numero_contactos);
                   	 break;
                   	 case 4: 
                     printf("numero de contactos :%d \n",numero_contactos );
                   	 ordenar_agenda(agenda, numero_contactos); 
                   	 break;
                   	 default:
                   	 break;
                   }

 }
}
