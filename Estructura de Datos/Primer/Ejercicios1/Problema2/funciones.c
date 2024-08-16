#include <stdio.h>
#include "funciones.h"

float
descuento (sueldo_base)
{
  float descuento = 0.0f;
  float sueldo_neto = 0.0f;
  const float Descuento_1 = 0.05f;
  const float Descuento_2 = 0.15f;
  const float Descuento_3 = 0.30f;
  const int rango_1 = 1000;
  const int rango_2 = 5000;
  const int rango_3 = 5001;
  if (sueldo_base <= rango_1)
    {
      descuento = sueldo_base * Descuento_1;
      sueldo_neto = sueldo_base - descuento;
    }
  if (sueldo_base <= rango_2 && sueldo_base >= rango_1)
    {
      descuento = sueldo_base * Descuento_2;
      sueldo_neto = sueldo_base - descuento;
    }
  if (sueldo_base >= rango_3)
    {
      descuento = sueldo_base * Descuento_3;
      sueldo_neto = sueldo_base - descuento;
    }

  return sueldo_neto;
}
