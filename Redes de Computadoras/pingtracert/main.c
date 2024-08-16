#include "funciones.h"

int
main ()
{
  unsigned char tramaRev2[1514];                        //Variable para almacenar la respuesta de Eco.
  unsigned char identificador1[1];
  unsigned char identificador2[1];
  int ttl = 1;
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
      printf ("\nExito al abrir el socket\n");
      indice = obtenerDatos (packet_socket);
      resuelveARP (packet_socket, indice);
      bandera = bienvenida();
      identificador1[0] = randomSec(contador2);
      identificador2[0] = randomSec(contador2);
      while(Opcion != 2)
       {
         solicitudEco(bandera, packet_socket, indice, identificador1, identificador2, secuencia, contador, ttl);
         secuencia[0] = secuencia[0] + 1;
         Opcion = recibeTrama(packet_socket, tramaRev2, identificador1, identificador2, ttl);
         ttl++;
         contador++;
         i++;
         //Opcion = capturaOpcion(opcion);
       }
    }
  return 0;
}
