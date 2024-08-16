#include "funciones.h"
#include "funciones2.h"

int main()
{
	int status;
	int i, call_flag, msg_flag;
	llamadas *ptr1;
	mensajes *ptr2;
	condicion *parar;
	key_t llave, llave2, llave3;
	llave = ftok("/bin/ls",21);
	llave2 = ftok("/bin/ls",22);
	llave3 = ftok("/bin/ls",23);
	crear_ligar_sem(llave);
	ptr1 = crear_ligar_mem1(llave);
	ptr2 = crear_ligar_mem2(llave2);
	parar = crear_ligar_mem3(llave3);
	printf("semid:%d\t memid:%d memid2:%d\n",semid,memid,memid2);
	TOTAL = TODO;
	parar[1]->paro = TOTAL;
	printf("%d\n", TOTAL);

	for (i = 0; i < 3; i++)
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
				Consume(i, call_flag, msg_flag, ptr1, ptr2, parar);
				printf("EL consumidor %d termino de consumir\n", i);
				exit(0);
				break;
			default:
				/*Padre*/
				if (i == 0)
				{
					printf("Ha empezado a consumirse\n");
				}
				if (i == 2)
				{
					wait(&status);
					wait(&status);
					wait(&status);
					//break;
				}
				//break;
		}
	}

	//se desliga de la memoria
    shmdt(ptr1);
    shmdt(ptr2);
    printf("finaliza el consumo\n");
    shmctl(memid,IPC_RMID,0);
    shmctl(memid2, IPC_RMID,0);
    semctl(semid,0,IPC_RMID);
	return 0;
}