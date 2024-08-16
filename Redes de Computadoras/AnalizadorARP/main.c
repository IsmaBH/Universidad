#include "funciones.h"

unsigned char tramaEnv[1514];
unsigned char tramaRev[1514];
char mensaje[40];
int contador = 0;
MYSQL *con;

int
main ()
{
  int packet_socket, indice;
  packet_socket = socket (AF_PACKET, SOCK_RAW, htons (ETH_P_ALL));
  if (packet_socket == -1)
    {
      perror ("\nError al abrir el socket\n");
      exit (0);
    }
  else
    {
      con = mysql_init (NULL);
      printf ("\nExito al abrir el socket\n");
      indice = obtenerDatos (packet_socket);
      if (!mysql_real_connect (con, HOST, USER, PASS, DB, 3306, NULL, 0))
	{
	  fprintf (stderr, "%s\n", mysql_error (con));
	  return 1;
	}
      else
	{
	  while (contador <= 255)
	    {
	      cambiaIP ();
	      estructuraTrama (tramaEnv, mensaje);
	      enviaTrama (tramaEnv, packet_socket, indice);
	      recibeTrama (packet_socket, tramaRev, con);
	      contador++;
	    }
	}
    }

  return 0;
}
