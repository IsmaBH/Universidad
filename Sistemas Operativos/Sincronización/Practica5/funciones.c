#include "funciones.h"
#include "funciones2.h"

// -1 si error y 0 si exito semop
int doWait(int numsem,int semid)
{ 
    int id; 
    struct sembuf operacion;
    /*cerramos el semáforo del proceso padre*/
    operacion.sem_num = numsem;
    /*restamos una unidad al semáforo*/
    operacion.sem_op = -1;
    operacion.sem_flg = SEM_UNDO;
    /*aplicamos las operaciones, el 1 indica el numero de structuras que
    * tiene el arreglo*/
    id = semop(semid,&operacion,1);
    return id;
}

int doSignal(int numsem,int semid)
{
    int id;
    struct sembuf operacion;
    /*cerramos el semáforo del proceso padre*/
    operacion.sem_num = numsem;
/*restamos una unidad al semáforo*/
    operacion.sem_op = +1;
    operacion.sem_flg = SEM_UNDO;
    /*aplicamos las operaciones, el 1 indica el numero de structuras que
 * tiene el arreglo*/
    id = semop(semid,&operacion,1);
    return id;
}

llamadas * crear_ligar_mem1(key_t llave_mem)
{
    int i= 0;
    llamadas *ptr = NULL;

    if((memid = shmget(llave_mem,sizeof(llamadas),IPC_CREAT | IPC_EXCL| 0600)) == -1)
    {
    //ligando a la memoria
        if((memid = shmget(llave_mem,sizeof(llamadas), 0600)) == -1)
        {
            printf("no se puede ligar con la memoria\n");
            exit(-1);
        }
        else{
            printf("Se ligo a memoria\n");
        }
    }
    else{
        printf("Se creo memoria\n");
    }
    if((ptr = (llamadas *)shmat(memid,0,0)) == NULL)
    {
        printf("no se pude crear memoria compartida\n");
        exit(-1);
    }
    return ptr;
}

mensajes * crear_ligar_mem2(key_t llave_mem)
{
    int i= 0;
    mensajes *ptr = NULL;

    if((memid2 = shmget(llave_mem,sizeof(mensajes),IPC_CREAT | IPC_EXCL| 0600)) == -1)
    {
    //ligando a la memoria
        if((memid2 = shmget(llave_mem,sizeof(mensajes), 0600)) == -1)
        {
            printf("no se puede ligar con la memoria\n");
            exit(-1);
        }
        else{
            printf("Se ligo a memoria\n");
        }
    }
    else{
        printf("Se creo memoria\n");
    }
    if((ptr = (mensajes *)shmat(memid2,0,0)) == NULL)
    {
        printf("no se pude crear memoria compartida\n");
        exit(-1);
    }
    return ptr;
}

condicion * crear_ligar_mem3(key_t llave_mem)
{
    int i = 0;
    condicion *ptr = NULL;

    if((memid3 = shmget(llave_mem,sizeof(condicion),IPC_CREAT | IPC_EXCL| 0600)) == -1)
    {
    //ligando a la memoria
        if((memid3 = shmget(llave_mem,sizeof(condicion), 0600)) == -1)
        {
            printf("no se puede ligar con la memoria\n");
            exit(-1);
        }
        else{
            printf("Se ligo a memoria\n");
        }
    }
    else{
        printf("Se creo memoria\n");
    }
    if((ptr = (condicion *)shmat(memid3,0,0)) == NULL)
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
        else{
            printf("Se ligo semaforos\n");
        }
    }
    else
    {
        printf("Se crearon los semaforos\n");
        /*inicializamos los semáforos*/
        /*Se inicializa el semaforo de los productores y consumidores*/
        semctl(semid,SEM_PROD_LL,SETVAL,5);
        semctl(semid,SEM_PROD_MSG,SETVAL,5);
        semctl(semid,SEM_CONS_LL,SETVAL,0);
        semctl(semid,SEM_CONS_MSG,SETVAL,0);
        /*Se inicializa los semaforos de la seccion critica de las llamadas*/
        semctl(semid,SEM_SCL_1,SETVAL,1);
        semctl(semid,SEM_SCL_2,SETVAL,1);
        semctl(semid,SEM_SCL_3,SETVAL,1);
        semctl(semid,SEM_SCL_4,SETVAL,1);
        semctl(semid,SEM_SCL_5,SETVAL,1);
        /*Se inicializa los semaforos de la seccion critica de los mensajes*/
        semctl(semid,SEM_SCM_1,SETVAL,1);
        semctl(semid,SEM_SCM_2,SETVAL,1);
        semctl(semid,SEM_SCM_3,SETVAL,1);
        semctl(semid,SEM_SCM_4,SETVAL,1);
        semctl(semid,SEM_SCM_5,SETVAL,1);
        /*Se inicializa los semaforos de la seccion critica de los archivos*/
        semctl(semid,SEM_SCU1_1,SETVAL,1);
        semctl(semid,SEM_SCU1_2,SETVAL,1);
        semctl(semid,SEM_SCU2_1,SETVAL,1);
        semctl(semid,SEM_SCU2_2,SETVAL,1);
        semctl(semid,SEM_SCU3_1,SETVAL,1);
        semctl(semid,SEM_SCU3_2,SETVAL,1);
        semctl(semid,SEM_SCU4_1,SETVAL,1);
        semctl(semid,SEM_SCU4_2,SETVAL,1);
        /*Se inicializa el semaforo auxiliar*/
        semctl(semid,SEM_AUX,SETVAL,1);
    }
}