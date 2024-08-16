#include "funciones.h"

void
menu1 (MYSQL * con, char *consulta0, MYSQL_ROW row, MYSQL_RES * res)
{
  int opcion = 0;
  unsigned char IP[4];
  unsigned char MAC[6], eliminar[6];
  do
    {
      getchar ();
      system ("clear");
      fprintf (stdout, "_____________________________________________\n");
      fprintf (stdout, "____________________MENU_____________________\n");
      fprintf (stdout, "|0- Salir                       \t\t  |\n");
      fprintf (stdout, "|1- Mostrar datos               \t\t  |\n");
      fprintf (stdout, "|2- Agregar una MAC             \t\t  |\n");
      fprintf (stdout, "|3- Eliminar una MAC            \t\t  |\n");
      fprintf (stdout, "_____________________________________________\n");
      fprintf (stdout, "___________________OPCION:___________________\n");
      fscanf (stdin, "%d", &opcion);

      switch (opcion)
	{
	case 0:
	  break;
	case 1:
	  muestra1 (con, consulta0, row, res);
	  getchar ();
	  break;
	case 2:
	  fprintf (stdout, "Ingrese la IP nueva:\n");
	  scanf ("%hhu.%hhu.%hhu.%hhu", &IP[0], &IP[1], &IP[2], &IP[3]);
	  fprintf (stdout, "\nIngrese la MAC asociada a la IP:\n");
	  scanf ("%s:%s:%s:%s:%s:%s", &MAC[0], &MAC[1], &MAC[2], &MAC[3],
		 &MAC[4], &MAC[5]);
	  agrega1 (con, IP, MAC);
	  break;
	case 3:
	  fprintf (stdout, "Ingresa la MAC que quieres eliminar:\n");
	  scanf ("%s:%s:%s:%s:%s:%s", &eliminar[0], &eliminar[1],
		 &eliminar[2], &eliminar[3], &eliminar[4], &eliminar[5]);
	  elimina1 (con, eliminar);
	  break;
	default:
	  fprintf (stdout, "Opcion invalida, ingrese otra opcion:\n");
	  break;
	}
    }
  while (opcion != 0);
}

void
menu2 (MYSQL * con, char *consulta1, MYSQL_ROW row, MYSQL_RES * res)
{
  int opcion = 0;
  unsigned char IP[4];
  unsigned char MAC[6], eliminar[6];
  char Descripcion[100];
  do
    {
      getchar ();
      system ("clear");
      fprintf (stdout, "_____________________________________________\n");
      fprintf (stdout, "____________________MENU_____________________\n");
      fprintf (stdout, "|0- Salir                       \t\t  |\n");
      fprintf (stdout, "|1- Mostrar datos               \t\t  |\n");
      fprintf (stdout, "|2- Agregar una MAC             \t\t  |\n");
      fprintf (stdout, "|3- Eliminar una MAC            \t\t  |\n");
      fprintf (stdout, "_____________________________________________\n");
      fprintf (stdout, "___________________OPCION:___________________\n");
      fscanf (stdin, "%d", &opcion);

      switch (opcion)
	{
	case 0:
	  break;
	case 1:
	  muestra2 (con, consulta1, row, res);
	  getchar ();
	  break;
	case 2:
	  fprintf (stdout, "\nIngrese la MAC a banear:\n");
	  scanf ("%s:%s:%s:%s:%s:%s", &MAC[0], &MAC[1], &MAC[2], &MAC[3],
		 &MAC[4], &MAC[5]);
	  fprintf (stdout, "\nIngrese el motivo:\n");
	  scanf ("%s", Descripcion);
	  agrega2 (con, MAC, Descripcion);
	  break;
	case 3:
	  fprintf (stdout, "Ingresa la MAC que quieres eliminar:\n");
	  scanf ("%s:%s:%s:%s:%s:%s", &eliminar[0], &eliminar[1],
		 &eliminar[2], &eliminar[3], &eliminar[4], &eliminar[5]);
	  elimina2 (con, eliminar);
	  break;
	default:
	  fprintf (stdout, "Opcion invalida, ingrese otra opcion:\n");
	  break;
	}
    }
  while (opcion != 0);
}

int
obtenerDatos2 (int ds)
{

  struct ifreq nic;
  int index, i;
  printf ("\nInserta el nombre: ");
  scanf ("%s", nic.ifr_name);
  if (ioctl (ds, SIOCGIFINDEX, &nic) == -1)
    {
      perror ("\nError al obtener indice\n");
      exit (0);
    }
  else
    {
      index = nic.ifr_ifindex;
      printf ("El indice es: %d\n", index);
    }

      printf ("\n");
  return index;
}

void flush_in(void) 
{ 
int ch; 
while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}
