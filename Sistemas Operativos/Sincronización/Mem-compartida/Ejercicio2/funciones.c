#include "funciones.h"

void doWait(int numsem,int semid)
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

void doSignal(int numsem,int semid)
{
    struct sembuf operacion;
    /*cerramos el semáforo del proceso padre*/
    operacion.sem_num = numsem;
/*restamos una unidad al semáforo*/
    operacion.sem_op = +1;
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
        /*Se inicializa el semaforo de los productores y consumidores*/
        semctl(semid,SEM_PRODUCTORES,SETVAL,3);
        semctl(semid,SEM_CONSUMIDORES,SETVAL,0);
        /*Se inicializa los semaforos de las secciones criticas*/
        semctl(semid,SEM_SC_1,SETVAL,1);
        semctl(semid,SEM_SC_2,SETVAL,1);
        semctl(semid,SEM_SC_3,SETVAL,1);
    }
}
