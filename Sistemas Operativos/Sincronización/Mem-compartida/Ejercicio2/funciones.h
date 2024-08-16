#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/wait.h>
#define SEM_PRODUCTORES 0
#define SEM_CONSUMIDORES 1
#define SEM_SC_1 2
#define SEM_SC_2 3
#define SEM_SC_3 4

#define NUM_SEM 5
#define PRODUCCION 10

int semid;
int memid;
typedef struct
{
    int bandera;
    char msg[10];
}seccion_crt[3];

void doWait(int numsem,int semid);
void doSignal(int numsem,int semid);
seccion_crt * crear_ligar_mem(key_t llave_mem);
void crear_ligar_sem(key_t llave);