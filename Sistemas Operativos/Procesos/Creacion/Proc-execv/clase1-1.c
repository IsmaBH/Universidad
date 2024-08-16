#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	char* comando[] = {"./doshijos", NULL};

    execv("/home/diego/Documentos/Operativos/Procesos/Creacion/EjercicioProc/doshijos", comando);
	return 0;
}