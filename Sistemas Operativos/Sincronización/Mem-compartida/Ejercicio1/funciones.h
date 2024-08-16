#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/wait.h>
#define SEM_CONSUMIDOR1 0
#define SEM_CONSUMIDOR2 1
#define SEM_PRODUCTOR1 2
#define SEM_PRODUCTOR2 3

#define NUM_SEM 4
#define PRODUCCION 20

int semid;
int memid;
typedef struct
{
    int bandera;
    char msg[10];
}seccion_crt[2];

void esperar(int numsem,int semid);
void avisar(int numsem,int semid);
seccion_crt * crear_ligar_mem(key_t llave_mem);
void crear_ligar_sem(key_t llave);