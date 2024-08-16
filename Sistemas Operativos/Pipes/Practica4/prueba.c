#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SIZE 512

int main(int argc, char const *argv[])
{
	int status, i;
	int fd, readbytes;
	char buffer[SIZE];
	char nombre[100];
	char * myfifoP = "/tmp/myfifo1";
	char *archivo1 = {"filtroR.py"};
	char *archivo2 = {"filtroG.py"};
	char *archivo3 = {"filtroB.py"};
	char comando[100];

	//Creamos un FIFO
  	//mkfifo(<pathname>, <permission>)
  	mkfifo(myfifoP, 0666);
	for(i=0; i<3; i++)
	{
		pid_t pid = fork();
		switch(pid)
		{
			case -1:
				printf("error al crear el hijo\n");
				return -1;
				break;
			case 0:
				fd = open(myfifoP, O_RDONLY);
				while( (readbytes=read(fd, buffer, SIZE)) > 0)
	  		  	{
	  		  		printf("Soy el hijo %d de PID: %d y recibi el siguiente mensaje: %s\n", i, getpid(), buffer);
	  		  		close(fd);
	  		  	}
	  		  	//close(fd);
				exit(0);
				break;
			default:
				if (i == 0)
				{
					printf("Soy el padre de PID: %d\n", getpid() );
					printf("Ingrese el nombre del archivo a tratar:\n");
					scanf("%s", nombre);
				}
				fd = open(myfifoP, O_WRONLY);
				strcpy(buffer, nombre);
				write(fd, buffer, strlen(buffer));
				close(fd);
				if(i==2)
				{
					wait(&status);
					wait(&status);
					wait(&status);
					exit(0);
				}
				break;
		}
	}
	return 0;
}