#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
	char* comando[] = {"./unNieto", NULL};

    execv("/home/diego/Documentos/Operativos/Procesos/Creacion/EjercicioProc/unNieto", comando);
    return 0;
}