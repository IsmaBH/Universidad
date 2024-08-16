#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 512

int main(int argc, char const *argv[])
{
	int status, i;
	int a[2], b[2], readbytes;
	char buffer[SIZE];
	char nombre[100];
	char *archivo1 = {"filtroR.py"};
	char *archivo2 = {"filtroG.py"};
	char *archivo3 = {"filtroB.py"};
	char comando[100];

	for(i=0;i<3;i++)
	{
		pid_t pid = fork();
		pipe(a);
		pipe(b);
		switch(pid)
		{
			case 0:
				close(a[1]); /*Cerramos el lado de escritura del pipe*/
				close(b[0]); /*Cerramos el lado de lectura del pipe*/
				strcpy(comando, archivo1);
				read(a[0], buffer, SIZE);
				strcat(comando, buffer);
				printf("soy el hijo de ID %d. Mi padre es %d",getpid(),getppid());
				printf("recibi el siguiente comando %s\n", comando);		
				break;
			case -1:
				printf("error al crear el hijo\n");
				return -1;
				break;
			default:
				if (i == 0)
				{
					printf("Introduzca el nombre de la imagen a tratar: \n");
					scanf("%s", nombre);
					strcpy(buffer, nombre);
					write(a[1], buffer, strlen(buffer));
					close(a[1]);
				}
				/*if(i==2)
				{
					wait(&status);
					wait(&status);
					wait(&status);
				}*/
			break;
		}
	}
	return 0;
}