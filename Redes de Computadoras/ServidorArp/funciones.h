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

void muestra1 (MYSQL * con, char *consulta0, MYSQL_ROW row, MYSQL_RES * res);
void muestra2 (MYSQL * con, char *consulta1, MYSQL_ROW row, MYSQL_RES * res);
void agrega1 (MYSQL * con, unsigned char *IP, unsigned char *MAC);
void agrega2 (MYSQL * con, char *MAC, unsigned char *Descripcion);
void elimina1 (MYSQL * con, unsigned char *eliminar);
void elimina2 (MYSQL * con, unsigned char *eliminar);
void modifica_tel (MYSQL * con, char *new_tel, char *per_tel);
void inicio(MYSQL * con);
void cambiaIP();
void imprimeTrama(unsigned char *paq, int len);
void recibeTrama(int ds, unsigned char *trama, MYSQL * con);
void enviaTrama(unsigned char *trama, int ds, int index);
char estructuraTrama(unsigned char *trama);
int obtenerDatos(int ds);
void menu1(MYSQL * con, char * consulta0, MYSQL_ROW row, MYSQL_RES * res);
void menu2(MYSQL * con, char * consulta1, MYSQL_ROW row, MYSQL_RES * res);
void escucha (int ds, unsigned char *trama, MYSQL * con, int index, MYSQL_ROW row, MYSQL_RES * res);
char GARP (unsigned char *trama, unsigned char *tramaEnv, unsigned char *Mac);
char GARPB (unsigned char *trama, unsigned char *tramaEnv, unsigned char *Mac);
void Serverup (MYSQL * con, MYSQL_ROW row, MYSQL_RES * res);
int obtenerDatos2 (int ds);
void flush_in(void);
unsigned char traducir1(char MAC);
unsigned char traducir2(char MAC);
unsigned char suma(unsigned char * num1, unsigned char * num2);
