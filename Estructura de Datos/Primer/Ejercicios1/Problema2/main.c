/* AUTOR: BARON HERNANDEZ DIEGO ISMAEL
   DESCRIPCION: Este programa calcula el salario que debe persivir un empleado tomando en cuenta el descuento
                que se hace conforme a cierto porcentaje a su salario base.
   COMPILACION: Este programa debe de poder ser compilado en Windows y Linux ya que esta en el estandar, para esto
                Usar el archivo "makefile" que esta incluido en la carpeta.
   OBSERVACIONES: Si no funcionase el archivo "makefile" para generar el ejecutable, en la consola digite las
                  instrucciones que vienen en dicho archivo para generar el ejecutable.
   LIBRERIAS: Se uso solamente la libreria de stdio.h que trabaja bajo el standar.
*/
#include <stdio.h>
#include "funciones.h"

int
main ()
{
  float sueldo_neto = 0;
  int sueldo_base = 0;
  printf ("Salario:");
  scanf ("%d", &sueldo_base);
  sueldo_neto = descuento (sueldo_base);
  printf ("\nEl sueldo total es: %f\n", sueldo_neto);
  return 0;
}
