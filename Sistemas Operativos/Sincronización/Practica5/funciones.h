#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>

#define SEM_PROD_LL 0
#define SEM_CONS_LL 1
#define SEM_PROD_MSG 2
#define SEM_CONS_MSG 3
#define SEM_SCL_1 4
#define SEM_SCL_2 5
#define SEM_SCL_3 6
#define SEM_SCL_4 7
#define SEM_SCL_5 8
#define SEM_SCM_1 9
#define SEM_SCM_2 10
#define SEM_SCM_3 11
#define SEM_SCM_4 12
#define SEM_SCM_5 13

#define SEM_SCU1_1 14
#define SEM_SCU1_2 15
#define SEM_SCU2_1 16
#define SEM_SCU2_2 17
#define SEM_SCU3_1 18
#define SEM_SCU3_2 19
#define SEM_SCU4_1 20
#define SEM_SCU4_2 21

#define SEM_AUX 22

#define NUM_SEM 23
#define PRODUCCION 10000
#define SUB PRODUCCION*4
#define TODO SUB*2

int semid;
int memid2;
int memid;
int memid3;
int TOTAL;

typedef struct
{
    int bandera;
    char tel[12];
    int P_ID;
}llamadas[5];

typedef struct
{
	int bandera;
	char msg[12];
	int P_ID;
}mensajes[5];

typedef struct
{
	int paro;
}condicion[1];

int doWait(int numsem,int semid);
int doSignal(int numsem,int semid);
llamadas * crear_ligar_mem1(key_t llave_mem);
mensajes * crear_ligar_mem2(key_t llave_mem);
condicion * crear_ligar_mem3(key_t llave_mem);
void crear_ligar_sem(key_t llave);