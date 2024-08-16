#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SIZE 512

int main(int argc, char const *argv[])
{
	pid_t pid;
	int fd1, fd2, readbytes;
	int flag = 0;
  	char mensaje[SIZE];
  	char termino[] = "fin";
  	char * myfifoP = "/tmp/myfifo1";
  	char * myfifoH = "/tmp/myfifo2";
 
  	//Creamos un FIFO
  	//mkfifo(<pathname>, <permission>)
  	mkfifo(myfifoP, 0666);
  	mkfifo(myfifoH, 0666);
 
  	if ( (pid=fork()) == 0 )
  	{ 
  		// hijo
  		while(1)
  		{
  			fd1 = open(myfifoP, O_RDONLY);
	  		read(fd1, &flag, 1);
	  		if (flag % 2 != 0)
	  		{
	  		  	flag++;
	  		  	while( (readbytes=read(fd1, mensaje, SIZE)) > 0)
	  		  	{
	  		  		printf("Soy el hijo de PID: %d y recibi el siguiente mensaje: %s\n", getpid(), mensaje);
	  		  	}
	  		  	close(fd1);
	  		  	scanf("%s", mensaje);
	  		  	//Enviamos atravez del FIFO Hijo el mensaje y la bandera
	  		  	fd2 = open(myfifoH, O_WRONLY);
	  		  	write(fd2, &flag, 1);
	  		  	write(fd2, mensaje, strlen(mensaje));
	  		  	close(fd2);
	  		}else{
	  			close(fd1);
	  		}
  		}  
  	}
  	else
  	{ 
  		// padre
  		while(1)
  		{
  			fd2 = open(myfifoH, O_RDONLY);
  			if (flag > 0)
  			{
  				read(fd2, &flag, 1);
  			}
  			if (flag % 2 == 0)
  			{
  				flag++;
  				fd1 = open(myfifoP, O_WRONLY);
	  			scanf("%s", mensaje);
	  			//Enviamos atraves del FIFO Padre el mensaje y la bandera
	  			write(fd1, &flag, 1);
	  			write(fd1, mensaje, strlen(mensaje));
	  			close(fd1);
  			}
  			if (flag % 2 != 0)
  			{
	  			flag++;
	  			while( (readbytes=read(fd2, mensaje, SIZE)) > 0)
	  		  	{
	  		  		printf("Soy el padre de PID: %d y recibi el siguiente mensaje: %s\n", getpid(), mensaje);
	  		  	}
	  		  	close(fd2);
  			}else{
  				close(fd2);
  			}
  		}
  	}
  	waitpid( pid, NULL, 0 );
  	exit( 0 );
}