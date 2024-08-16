#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int fn(void *arg)
{
  printf("Soy el hijo: PID %d; PPID = %d \n", getpid(),  getppid());
   return 0;
}

void main(int argc, char *argv[])
{
   int status;
   void *pchild_stack = malloc(1024 * 1024);
   if ( pchild_stack == NULL ) {
      printf("ERROR: Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
   }

   printf("Soy el padre: PID %d; PPID = %d \n", getpid(),  getppid());

   for(int i = 0; i < 2; i++){
	   int pid = clone(fn, pchild_stack + (1024 * 1024), SIGCHLD, argv[1]);
      wait(&status);
	   if ( pid < 0 ) {
	        printf("ERROR: Unable to create the child process.\n");
	        exit(EXIT_FAILURE);
	   }
   }
   wait(NULL);
   free(pchild_stack);
}