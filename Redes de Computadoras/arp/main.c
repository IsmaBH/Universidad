#include "funciones.h"

unsigned char tramaEnv[1514];
unsigned char tramaRev[1514];
char mensaje[40];

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
      printf ("\nExito al abrir el socket\n");
      indice = obtenerDatos (packet_socket);
//escribeMsn(mensaje);
//memcmp(tramaEnv,estructuraTrama(buffer, mensaje),1514);
      estructuraTrama (tramaEnv, mensaje);
      enviaTrama (tramaEnv, packet_socket, indice);
      recibeTrama (packet_socket, tramaRev);
    }

  return 0;
}
