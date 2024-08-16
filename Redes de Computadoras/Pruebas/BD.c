// COMPILAR gcc -L/usr/lib64/mysql my.c -o my -lm -lmysqlclient

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASS "root"
#define DB   "IPTABLES"

void muestra (MYSQL * con, char *consulta0, MYSQL_ROW row, MYSQL_RES * res, unsigned char *IP, unsigned char *MAC);
void agrega (MYSQL * con, char *persona, unsigned char *telefono);
void elimina (MYSQL * con, char *eliminar);
void modifica_tel (MYSQL * con, unsigned char *new_tel, char *per_tel);

void flush_in(void) 
{ 
int ch; 
while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int
main (void)
{
  MYSQL *con;
  MYSQL_ROW row;
  MYSQL_RES *res;
  char persona[20], eliminar[20], per_tel[20];
  unsigned char telefono[10], new_tel[10];
  char consulta0[1024];
  int opcion = 1;
  unsigned char IP[8];
  unsigned char MAC[12];
  unsigned char IpAux[16] = "8.12.0.4";

  con = mysql_init (NULL);

  if (!mysql_real_connect (con, HOST, USER, PASS, DB, 3306, NULL, 0))
    {      
	fprintf (stderr, "%s\n", mysql_error (con));
      	exit(EXIT_FAILURE);
    }
  fprintf (stdout, "--> Conectando a Base de Datos: %s\n", DB);
  sprintf (consulta0, "SELECT IP_RESIDTRADA, MAC_ASOCIADA FROM red WHERE IP_RESIDTRADA = '%s';", IpAux);
  /*sprintf (consulta0, "SELECT * FROM red");*/
  do
    {
      //getchar ();
      //system ("clear");
      fprintf (stdout, "_____________________________________________\n");
      fprintf (stdout, "____________________MENU_____________________\n");
      fprintf (stdout, "|0- Salir           \t\t  |\n");
      fprintf (stdout, "|1- Mostrar personas\t\t  |\n");
      fprintf (stdout, "|2- Insertar persona\t\t  |\n");
      fprintf (stdout, "|3- Eliminar persona\t\t  |\n");
      fprintf (stdout, "|4- Modificar telefono de persona |\n");
      fprintf (stdout, "_____________________________________________\n");
      fprintf (stdout, "___________________OPCION:___________________\n");
      fscanf (stdin, "%d", &opcion);

      switch (opcion)
	{
	case 0:
	  break;
	case 1:
	  fprintf (stdout, "\nDatos actuales en la Base\n");
	  muestra (con, consulta0, row, res, IP, MAC);
	printf ("RESULTADO:\n%s\n", IP);
       	printf ("%s\n", MAC);
	flush_in();
	  //getchar ();
	  break;
	case 2:
	  fprintf (stdout, "Ingrese el nombre de la persona a ingresar\n");
	  fscanf (stdin, "%s", &persona);
	  fprintf (stdout, "\nIngrese el telefono de la persona\n");
	  fscanf (stdin, "%s", &telefono);
	  agrega (con, persona, telefono);
	  break;
	case 3:
	  fprintf (stdout, "Ingresar el nombre de la persona a eliminar\n");
	  fscanf (stdin, "%s", &eliminar);
	  elimina (con, eliminar);
	  break;
	case 4:
	  fprintf (stdout, "Ingrese el nombre de la persona a modificar\n");
	  fscanf (stdin, "%s", &per_tel);
	  fprintf (stdout, "\nIngrese el telefono de la persona\n");
	  fscanf (stdin, "%s", &new_tel);
	  modifica_tel (con, new_tel, per_tel);
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

void
muestra (MYSQL * con, char *consulta0, MYSQL_ROW row, MYSQL_RES * res, unsigned char *IP, unsigned char *MAC)
{
  if (!mysql_query (con, consulta0))
    {
      res = mysql_store_result (con);
	if(res == NULL)
		exit(1);
      printf ("|Nombre   |\tTelefono   |\n");
      printf ("_ _ _ _ _ _ _ _ _ _ _ _ _\n");
      while ((row = mysql_fetch_row (res)) != NULL)
	{
          printf ("|%s\t", row[0]);
	  printf (" %s\t|\n", row[1]);
	strcpy(IP, row[0]);
	strcpy(MAC, row[1]);
	}
      if (!mysql_eof (res))
	{
	  printf ("Error de lectura: [%s]\n", mysql_error (con));
	}
    }
flush_in();
}

void
agrega (MYSQL * con, char *persona, unsigned char *telefono)
{
  char consulta[1024];
  sprintf (consulta, "INSERT INTO persona VALUES('%s','%s')", persona,
	   telefono);
  if (mysql_query (con, consulta) == 0)
    fprintf (stdout, "\nDatos insertados con exito\n");
}

void
elimina (MYSQL * con, char *eliminar)
{
  char consulta[1024];
  sprintf (consulta, "DELETE FROM persona WHERE nombre='%s'", eliminar);
  if (mysql_query (con, consulta) == 0)
    fprintf (stdout, "\nPersona eliminada con exito\n");
}

void
modifica_tel (MYSQL * con, unsigned char *new_tel, char *per_tel)
{
  char consulta[1024];
  sprintf (consulta, "UPDATE persona SET telefono='%s' WHERE nombre='%s'",
	   new_tel, per_tel);
  if (mysql_query (con, consulta) == 0)
    fprintf (stdout, "\nNo. de telefono cambiado\n");
}
