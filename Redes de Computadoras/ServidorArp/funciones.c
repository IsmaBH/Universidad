#include "funciones.h"

void
muestra1 (MYSQL * con, char *consulta0, MYSQL_ROW row, MYSQL_RES * res)
{
  if (mysql_query (con, consulta0))
    {
      res = mysql_use_result (con);
      printf ("|IP_REGISTRADA|\t|MAC_ASOCIADA|\n");
      printf ("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
      while ((row = mysql_fetch_row (res)))
	{
	  printf ("|%s\t", row[0]);
	  printf (" %s\t|\n", row[1]);
	}
      if (!mysql_eof (res))
	{
	  printf ("Error de lectura: [%s]\n", mysql_error (con));
	}
    }
}

void
muestra2 (MYSQL * con, char *consulta1, MYSQL_ROW row, MYSQL_RES * res)
{
  if (mysql_query (con, consulta1))
    {
      res = mysql_use_result (con);
      printf ("|MAC_BANEADA|\t|DESCRIPCION_ |\n");
      printf ("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
      while ((row = mysql_fetch_row (res)))
	{
	  printf ("|%s\t", row[0]);
	  printf (" %s\t|\n", row[1]);
	}
      if (!mysql_eof (res))
	{
	  printf ("Error de lectura: [%s]\n", mysql_error (con));
	}
    }
}

void
agrega1 (MYSQL * con, unsigned char *IP, unsigned char *MAC)
{
  char consulta[1024];
  sprintf (consulta, "INSERT INTO red VALUES('%d.%d.%d.%d','%s')", IP[0],
	   IP[1], IP[2], IP[3], MAC);
  if (mysql_query (con, consulta) == 0)
    fprintf (stdout, "\nDatos insertados con exito\n");
}

void
elimina1 (MYSQL * con, unsigned char *eliminar)
{
  char consulta[1024];
  sprintf (consulta, "DELETE FROM red WHERE MAC_ASOCIADA='%s'", eliminar);
  if (mysql_query (con, consulta) == 0)
    fprintf (stdout, "\nPersona eliminada con exito\n");
}

void
agrega2 (MYSQL * con, char *MAC, unsigned char *Descripcion)
{
  char consulta[1024];
  sprintf (consulta, "INSERT INTO red VALUES('%s', '%s')", MAC, Descripcion);
  if (mysql_query (con, consulta) == 0)
    fprintf (stdout, "\nDatos insertados con exito\n");
}

void
elimina2 (MYSQL * con, unsigned char *eliminar)
{
  char consulta[1024];
  sprintf (consulta, "DELETE FROM ban WHERE MAC_BANEADA='%s'", eliminar);
  if (mysql_query (con, consulta) == 0)
    fprintf (stdout, "\nPersona eliminada con exito\n");
}
