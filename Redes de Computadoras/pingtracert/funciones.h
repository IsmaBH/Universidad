#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <time.h>


void imprimeTrama(unsigned char *paq, int len);
int recibeTrama(int ds, unsigned char *trama,unsigned char *identificador1, unsigned char *identificador2, int ttl);
void enviaTrama(unsigned char *trama, int ds, int index);
int obtenerDatos(int ds);
void resuelveARP (int ds, int index);
int bienvenida();
void solicitudEco(int bandera, int ds, int index,unsigned char *identificador1,unsigned char *identificador2, unsigned char *secuencia, int contador, int ttl);
unsigned char randomSec(int contador);
unsigned short sacarchecksum (unsigned char *buffer, int bufflen);


