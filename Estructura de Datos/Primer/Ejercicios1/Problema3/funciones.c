#include <stdio.h>
#include "funciones.h"

void
ordenar (num_1, num_2, num_3)
{
  if (num_1 < num_2 && num_2 < num_3)
    {
      printf ("\nEl ordenamiento es: %d, %d, %d\n", num_3, num_2, num_1);
    }
  if (num_1 > num_2 && num_3 > num_2 && num_1 > num_3)
    {
      printf ("\nEl ordenamiento es: %d, %d, %d\n", num_1, num_3, num_2);
    }
  if (num_1 > num_2 && num_1 > num_3 && num_2 > num_3)
    {
      printf ("\nEl ordenamiento es: %d, %d, %d\n", num_1, num_2, num_3);
    }
  if (num_1 > num_2 && num_1 < num_3)
    {
      printf ("\nEl ordenamiento es: %d, %d, %d\n", num_3, num_1, num_2);
    }
  if (num_1 < num_2 && num_2 > num_3 && num_1 > num_3)
    {
      printf ("\nEl ordenamiento es: %d, %d, %d\n", num_2, num_1, num_3);
    }
  if (num_1 < num_2 && num_2 > num_3 && num_1 < num_3)
    {
      printf ("\nEl ordenamiento es: %d, %d, %d\n", num_2, num_3, num_1);
    }
}
