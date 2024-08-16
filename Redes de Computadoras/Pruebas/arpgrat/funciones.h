#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>

char escribeMsn(char *mensaje);
void imprimeTrama(unsigned char *paq, int len);
void recibeTrama(int ds, unsigned char *trama);
void enviaTrama(unsigned char *trama, int ds, int index);
char estructuraTrama(unsigned char *trama, char *mensaje);
int obtenerDatos(int ds);
