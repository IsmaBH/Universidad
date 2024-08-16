#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
 
#define SIZE 512
 
int main( int argc, char **argv )
{
  pid_t pid;
  int p[2], readbytes;
  char buffer[SIZE];
 
  pipe( p );
 
  if ( (pid=fork()) == 0 )
  { 
    close( p[0] ); /* cerramos el lado de lectura del pipe */
    strcpy( buffer, "Esto llega a traves de la tuberia\n" );
    write( p[1], buffer, strlen( buffer ) );
    printf("Soy el hijo con PID: %d y envio el siguiente mensaje: ",getpid());
    printf("%s\n", buffer);
    close( p[1] );
  }
  else
  { 
    // padre
    close( p[1] ); /* cerramos el lado de escritura del pipe */
 
    while( (readbytes=read( p[0], buffer, SIZE )) > 0)
      //write( 1, buffer, readbytes );
    printf("Soy el padre de PID: %d y recibi el siguiente mensaje: ",getpid());
    printf("%s\n", buffer);
    close( p[0] );
  }
  waitpid( pid, NULL, 0 );
  exit( 0 );
}