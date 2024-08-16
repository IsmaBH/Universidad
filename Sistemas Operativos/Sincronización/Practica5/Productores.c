#include "funciones.h"
#include "funciones2.h"

int main()
{
	int status;
	int i, call_flag, msg_flag;
	llamadas *ptr1;
	mensajes *ptr2;
	key_t llave, llave2;
	llave = ftok("/bin/ls",21);
	llave2 = ftok("/bin/ls",22);
	crear_ligar_sem(llave);
	ptr1 = crear_ligar_mem1(llave);
	ptr2 = crear_ligar_mem2(llave2);
	printf("semid:%d\t memid1:%d memid2:%d\n",semid,memid,memid2);

	for (i = 0; i < 4; i++)
	{
		pid_t pid = fork();
		switch(pid)
		{
			case -1:
				printf("error al crear el hijo\n");
				return -1;
				break;
			case 0:
				/*hijos*/
				Produce(i, call_flag, msg_flag, ptr1, ptr2);
				exit(0);
				break;
			default:
				/*Padre*/
				if (i == 0)
				{
					printf("Ha empezado la Producción\n");
				}
				if (i == 3)
				{
					wait(&status);
					wait(&status);
					wait(&status);
					wait(&status);
				}
				//break;
		}
	}

	//se desliga de la memoria
    shmdt(ptr1);
    shmdt(ptr2);
    printf("finaliza la producción\n");
    shmctl(memid,IPC_RMID,0);
    shmctl(memid2, IPC_RMID,0);
    semctl(semid,0,IPC_RMID);
	return 0;
}