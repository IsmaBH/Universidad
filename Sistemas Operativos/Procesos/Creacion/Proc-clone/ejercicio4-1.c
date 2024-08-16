#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int fn2(void *arg)
{
  printf("Soy el hijo: PID %d; PPID = %d \n", getpid(),  getppid());


   return 0;
}

int fn(void *arg)
{
  printf("Soy el hijo: PID %d; PPID = %d \n", getpid(),  getppid());
  void *pchild_stack = malloc(1024 * 1024);
   if ( pchild_stack == NULL ) {
      printf("ERROR: Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
   }
   int status;
  int pid = clone(fn2, pchild_stack + (1024 * 1024), SIGCHLD);
    wait(status);
   return 0;
}

void main(int argc, char *argv[])
{
   void *pchild_stack = malloc(1024 * 1024);
   if ( pchild_stack == NULL ) {
      printf("ERROR: Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
   }

   printf("Soy el padre: PID %d; PPID = %d \n", getpid(), getppid());

      int pid = clone(fn, pchild_stack + (1024 * 1024), SIGCHLD);
      if ( pid < 0 ) {
           printf("ERROR: Unable to create the child process.\n");
           exit(EXIT_FAILURE);
      }
   wait(NULL);
   free(pchild_stack);
}