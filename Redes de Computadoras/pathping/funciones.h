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
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASS "root"
#define DB   "PATH"


void imprimeTrama(unsigned char *paq, int len);
int recibeTrama(int ds, unsigned char *trama,unsigned char *identificador1, unsigned char *identificador2, int ttl, MYSQL *con);
void enviaTrama(unsigned char *trama, int ds, int index);
int obtenerDatos(int ds);
void resuelveARP (int ds, int index, MYSQL *con);
int bienvenida();
void solicitudEco(int bandera, int ds, int index,unsigned char *identificador1,unsigned char *identificador2, unsigned char *secuencia, int contador, int ttl);
unsigned char randomSec(int contador);
unsigned short sacarchecksum (unsigned char *buffer, int bufflen);
void Ecojusto(MYSQL *con, MYSQL_RES *res, MYSQL_ROW row, int ds, int index, unsigned char *identificador1, unsigned char *identificador2, unsigned char *secuencia, int contador);
void EstructuraEco(unsigned char *IpNodo, int ttl, int ds, int index, unsigned char *identificador1, unsigned char *identificador2, unsigned char *secuencia, int contador);
int recibe (int ds, unsigned char *tramaRev, unsigned char *identificador1, unsigned char *identificador2, int ttl, MYSQL *con, unsigned char *Ipsol);
void Estadistica(MYSQL * con, char *consulta0, MYSQL_ROW row, MYSQL_RES * res);
void EcoMaximo(MYSQL *con, MYSQL_RES *res, MYSQL_ROW row, int ds, int index, unsigned char *identificador1, unsigned char *identificador2, unsigned char *secuencia, int contador);
void Estadistica2(MYSQL * con, char *consulta0, MYSQL_ROW row, MYSQL_RES * res);


