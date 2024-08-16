#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define HOST "localhost"
#define USER "root"
#define PASS "root"
#define DB   "IPTABLES"

void cambiaIP();
void imprimeTrama(unsigned char *paq, int len);
void recibeTrama(int ds, unsigned char *trama, MYSQL * con);
void enviaTrama(unsigned char *trama, int ds, int index);
char estructuraTrama(unsigned char *trama, char *mensaje);
int obtenerDatos(int ds);
/*void agrega (MYSQL * con, char *IpT, char *MACT);*/
