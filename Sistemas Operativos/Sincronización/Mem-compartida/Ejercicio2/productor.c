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
        while (j < PRODUCCION)
        {
            doWait(SEM_PRODUCTORES,semid);
            for (int k = 0; k < 3; ++k)
            {
                switch(k){
                    case 0:
                        doWait(SEM_SC_1, semid);
                    case 1:
                        doWait(SEM_SC_2, semid);
                    case 2:
                        doWait(SEM_SC_3, semid);
                }
                if (ptr[k]->bandera != 1)
                {
                    strcpy(ptr[k]->msg,"zzz");
                    ptr[k]->bandera = 1;
                    printf("Productor2, escribio:%s en seccion_crt[%d]\n",ptr[k]->msg, k);
                    switch(k){
                        case 0:
                            doSignal(SEM_SC_1, semid);
                        case 1:
                            doSignal(SEM_SC_2, semid);
                        case 2:
                            doSignal(SEM_SC_3, semid);
                    }
                    break;
                }
                else{
                    switch(k){
                        case 0:
                            doSignal(SEM_SC_1, semid);
                        case 1:
                            doSignal(SEM_SC_2, semid);
                        case 2:
                            doSignal(SEM_SC_3, semid);
                    }
                }
            }
            j++;
            doSignal(SEM_CONSUMIDORES, semid);
        }
    }
    else 
    {
        int estado;
        int p = 0;
        while (p < PRODUCCION)
        {
            doWait(SEM_PRODUCTORES,semid);
            for (int k = 0; k < 3; ++k)
            {
                switch(k){
                    case 0:
                        doWait(SEM_SC_1, semid);
                    case 1:
                        doWait(SEM_SC_2, semid);
                    case 2:
                        doWait(SEM_SC_3, semid);
                }
                if (ptr[k]->bandera != 1)
                {
                    strcpy(ptr[k]->msg,"aaa");
                    ptr[k]->bandera = 1;
                    printf("Productor1, escribio:%s en seccion_crt[%d]\n",ptr[k]->msg, k);
                    switch(k){
                        case 0:
                            doSignal(SEM_SC_1, semid);
                        case 1:
                            doSignal(SEM_SC_2, semid);
                        case 2:
                            doSignal(SEM_SC_3, semid);
                    }
                    break;
                }
                else{
                    switch(k){
                        case 0:
                            doSignal(SEM_SC_1, semid);
                        case 1:
                            doSignal(SEM_SC_2, semid);
                        case 2:
                            doSignal(SEM_SC_3, semid);
                    }
                }
            }
            p++;
            doSignal(SEM_CONSUMIDORES,semid);
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