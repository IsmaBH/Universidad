#include "funciones.h"

int main(int argc, char **argv)
{
    key_t llave;
    seccion_crt *ptr;
    llave = ftok("/bin/ls",21);
    crear_ligar_sem(llave);
    ptr = crear_ligar_mem(llave);
    int i = 0;
    pid_t pid;
    printf("semid:%d\t memid:%d\n",semid,memid);

    if((pid = fork()) == -1)
    {
        printf("error\n");
        exit(-1);
    }
    else if ( pid == 0)
    {
        int j = 0;
        while (j < 10)
        {
            esperar(SEM_PRODUCTOR2,semid);
            strcpy(ptr[1]->msg,"z");
            printf("Productor2, escribio:%s en seccion_crt[1]\n",ptr[1]->msg);
            j++;
            avisar(SEM_CONSUMIDOR2,semid);
        }
    }
    else 
    {
        int estado;
        while (i < 10)
        {
            esperar(SEM_PRODUCTOR1,semid);
            strcpy(ptr[0]->msg,"a");
            printf("Productor1, escribio:%s en seccion_crt[0]\n",ptr[0]->msg);
            i++;
            avisar(SEM_CONSUMIDOR1,semid);
        }
        wait(&estado);
    }
    
    //se desliga de la memoria
    shmdt(ptr);
    printf("finaliza la producción\n");
    shmctl(memid,IPC_RMID,0);
    semctl(semid,0,IPC_RMID);
    
    return 0;
}