#include "funciones.h"

int
main ()
{
  unsigned char tramaRev2[1514];                        //Variable para almacenar la respuesta de Eco.
  unsigned char identificador1[1];
  unsigned char identificador2[1];
  int ttl = 1;
  int justo = 0;
  int Maximo = 0;
  MYSQL *con;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char consulta[1024];
  char consulta0[1024];
  char consulta1[1024];
  unsigned char secuencia[2] = {0x01,0x00};
  int Opcion;
  int packet_socket, indice, bandera, i = 0, contador = 0;
  int contador2 = 1;
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
      resuelveARP (packet_socket, indice, con);
      bandera = bienvenida();
      identificador1[0] = randomSec(contador2);
      identificador2[0] = randomSec(contador2);
      if (!mysql_real_connect (con, HOST, USER, PASS, DB, 3306, NULL, 0))
       {
          fprintf (stderr, "%s\n", mysql_error (con));
	  return 1;
       }
         while(Opcion != 2)
            {
            solicitudEco(bandera, packet_socket, indice, identificador1, identificador2, secuencia, contador, ttl);
            secuencia[0] = secuencia[0] + 1;
            Opcion = recibeTrama(packet_socket, tramaRev2, identificador1, identificador2, ttl, con);
            ttl++;
            contador++;
            i++;
            }
         while(justo <= 99)
            {
              identificador1[0] = randomSec(contador2);
              identificador2[0] = randomSec(contador2);
              Ecojusto(con, res, row, packet_socket, indice, identificador1, identificador2, secuencia, contador);
              justo++;
            }
          sprintf (consulta0, "select * from Nodos;");
          Estadistica(con, consulta0, row, res);
          sprintf (consulta1, "update Nodos set LOST = '0';");
          if (mysql_query (con, consulta1) == 0)
           {
             fprintf (stdout, "\nResultado para ttl maximo:\n");
           }
         while(Maximo <= 99)
            {
              identificador1[0] = randomSec(contador2);
              identificador2[0] = randomSec(contador2);
              EcoMaximo(con, res, row, packet_socket, indice, identificador1, identificador2, secuencia, contador);
              Maximo++;
            }
          sprintf (consulta0, "select * from Nodos;");
          Estadistica2(con, consulta0, row, res);
    }
  sprintf (consulta, "delete from Nodos;");
  if (mysql_query (con, consulta) == 0)
   {
     fprintf (stdout, "\nAdios :'v\n");
   }
  return 0;
}
