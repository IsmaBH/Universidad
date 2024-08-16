#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define SIZE 512

int main(int argc, char const *argv[])
{
	pid_t pid;
	int flag = 0;
  	int a[2], b[2], readbytes;
  	char buffer[SIZE];
  	char mensaje[SIZE];
  	char termino[] = "fin";

  	pipe( a );
  	pipe( b );
 
  	if ( (pid=fork()) == 0 )
  	{ 
  		// hijo
  		close( a[1] ); /* cerramos el lado de escritura del pipe */
	   	close( b[0] ); /* cerramos el lado de lectura del pipe */
	    while(1)
	    {
	   		read(a[0] , &flag, 1);
	   		//printf("%d\n", flag);
	 		if (flag % 2 != 0)
	 		{
	 			flag++;
	 			while( (readbytes=read( a[0], buffer, SIZE ) ) > 0)
	 			{
	 				printf("Soy el hijo con PID: %d y recibi el siguiente mensaje: %s\n", getpid(), buffer);
	 				close( a[0]);
	 			}
	 			scanf("%s", mensaje);
		    	strcpy( buffer, mensaje );
		    	write( b[1], &flag , 1);
		    	write( b[1], buffer, strlen( buffer ) );
		    	close( b[1] );
		    	if (flag >= 1)
		   		{
		   			pipe( a );
	  				pipe( b );
		   			close( a[1] ); /* cerramos el lado de escritura del pipe */
		   			close( b[0] ); /* cerramos el lado de lectura del pipe */
		   		}
	 		}
	    }
	    //close(a[0]);
	    //close(b[1]);
  	}
  	else
  	{ 
  		// padre
  		close( a[0] ); /* cerramos el lado de lectura del pipe */
    	close( b[1] ); /* cerramos el lado de escritura del pipe */
 		while(1)
 		{
 			if (flag > 0)
 			{
 				read(b[0], &flag, 1);
 			}
 			if (flag % 2 == 0)
	 		{
	 			flag++;
	 			scanf("%s", mensaje);
	 			strcpy( buffer, mensaje );
	 			write( a[1], &flag, 1 );
	    		write( a[1], buffer, strlen( buffer ) );
	    		close( a[1]);
	    		if (flag % 2 != 0)
	 			{
	 				while( (readbytes=read( b[0], buffer, SIZE )) > 0)
	 				{
	 					printf("Soy el padre con PID: %d y recibi el siguiente mensaje: %s\n", getpid(), buffer);
	 					close( b[0]);
	 				}
	 				//flag++;
	 			}
	 			if (flag >= 0)
	 			{
	 				pipe( a );
	 				pipe( b );
	 				close( a[0] ); /* cerramos el lado de lectura del pipe */
	    			close( b[1] ); /* cerramos el lado de escritura del pipe */
 				}
	 		}
 		}
 		waitpid( pid, NULL, 0 );
  		exit( 0 );
  	}
}