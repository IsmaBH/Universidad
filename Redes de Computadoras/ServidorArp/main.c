#include "funciones.h"

int
main ()
{
  MYSQL *con;
  MYSQL_ROW row;
  MYSQL_RES *res;
  char consulta0[1024];
  char consulta1[1024];
  int opcion = 1;

  con = mysql_init (NULL);

  if (!mysql_real_connect (con, HOST, USER, PASS, DB, 3306, NULL, 0))
    {
      fprintf (stderr, "%s\n", mysql_error (con));
      return 1;
    }
  fprintf (stdout, "--> Conectando a Base de Datos: %s\n", DB);
  sprintf (consulta0, "SELECT * FROM red");
  sprintf (consulta1, "SELECT * FROM ban");
  do
    {
      getchar ();
      system ("clear");
      fprintf (stdout, "_____________________________________________\n");
      fprintf (stdout, "____________________MENU_____________________\n");
      fprintf (stdout, "|0- Salir                       \t\t  |\n");
      fprintf (stdout, "|1- Escanear red                \t\t  |\n");
      fprintf (stdout, "|2- Modificar tabla de validos  \t\t  |\n");
      fprintf (stdout, "|3- Modificar tabla de invalidos\t\t  |\n");
      fprintf (stdout, "|4- Activar el servidor |\n");
      fprintf (stdout, "_____________________________________________\n");
      fprintf (stdout, "___________________OPCION:___________________\n");
      fscanf (stdin, "%d", &opcion);

      switch (opcion)
	{
	case 0:
	  break;
	case 1:
	  inicio (con);
	  fprintf (stdout, "RED ESCANEADA ....... \n");
	  getchar ();
	  break;
	case 2:
	  menu1 (con, consulta0, row, res);
	  break;
	case 3:
	  menu2 (con, consulta1, row, res);
	  break;
	case 4:
	  Serverup(con, row, res);
	default:
	  fprintf (stdout, "Opcion invalida, ingrese otra opcion:\n");
	  break;
	}
    }
  while (opcion != 0);
  mysql_close (con);
  fprintf (stdout, "\n--> Desconectando a Base de datos: %s\n", DB);
  return 0;
}
