#include "funciones.h"

void esperar(int numsem,int semid)
{  
    struct sembuf operacion;
    /*cerramos el semáforo del proceso padre*/
    operacion.sem_num = numsem;
    /*restamos una unidad al semáforo*/
    operacion.sem_op = -1;
    operacion.sem_flg = SEM_UNDO;
    /*aplicamos las operaciones, el 1 indica el numero de structuras que
    * tiene el arreglo*/
    semop(semid,&operacion,1);
}

void avisar(int numsem,int semid)
{
    struct sembuf operacion;
    /*cerramos el semáforo del proceso padre*/
    operacion.sem_num = numsem;
/*restamos una unidad al semáforo*/
    operacion.sem_op = 1;
    operacion.sem_flg = SEM_UNDO;
    /*aplicamos las operaciones, el 1 indica el numero de structuras que
 * tiene el arreglo*/
    semop(semid,&operacion,1);
}

seccion_crt * crear_ligar_mem(key_t llave_mem)
{
    int i= 0;
    seccion_crt *ptr = NULL;

    if(
    (memid = shmget(llave_mem,sizeof(seccion_crt),IPC_CREAT | IPC_EXCL| 0600)) == -1)
    {

    //ligando a la memoria
        if((memid = shmget(llave_mem,sizeof(seccion_crt), 0600)) == -1)
        {
            printf("no se puede ligar con la memoria\n");
            exit(-1);
        }
        else
            printf("productor se ligo a memoria\n");
    }
    else
        printf("productor creo memoria\n");

    if((ptr = (seccion_crt *)shmat(memid,0,0)) == NULL)
    {
        printf("no se pude crear memoria compartida\n");
        exit(-1);
    }

    return ptr;
}
void crear_ligar_sem(key_t llave)
{
    if((semid = semget(llave,NUM_SEM,IPC_CREAT| IPC_EXCL | 0600)) == -1)
    {
        
        if((semid = semget(llave,NUM_SEM, 0600)) == -1)
        {
            printf("error al enlazar\n");
            exit(-1);
        }
        else
            printf("productor ligo semaforos\n");
    }
    else
    {
        printf("productor creo semaforos\n");
        /*inicializamos los semáforos*/
        /*cerramos el semáforo del proceso hijo*/
        semctl(semid,SEM_CONSUMIDOR1,SETVAL,0);
        semctl(semid,SEM_CONSUMIDOR2,SETVAL,0);
        /*Abrimos el semáforo del proceso padre*/
        semctl(semid,SEM_PRODUCTOR1,SETVAL,1);
        semctl(semid,SEM_PRODUCTOR2,SETVAL,1);
    }
}
