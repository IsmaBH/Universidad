#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid1, pid2;
    int status1, status2;

    if ((pid1=fork()) == 0)
    {
    	/*Hijo*/
    	printf("Soy el hijo: PID %d; PPID = %d\n", getpid(), getppid());
    	if ((pid2=fork()) == 0)
    	{
    		/*Hijo-Hijo*/
    		printf("Soy el hijo: PID %d; PPID = %d\n", getpid(), getppid());
    		exit(0);
    	}
    	/* Esperamos al primer hijo */
        waitpid(pid2, &status2, 0);
        exit(0);
    }
    else
    {
    	/*Padre*/
    	printf("Soy el padre: PID %d; PPID = %d\n", getpid(), getppid());
    	/* Esperamos al primer hijo */
        waitpid(pid1, &status1, 0);
        exit(0);
    }
	return 0;
}