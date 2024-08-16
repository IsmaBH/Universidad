/*Soy el Servidor*/
#include "funciones.h"
  
int main() 
{ 
    int fd1, fd2, fd3, i;
    int status;
  
    // FIFO file path 
    char * myfifo1 = "/tmp/myfifo1";
    //char * myfifo2 = "/tmp/myfifo2";
    int opt = -1;
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    mkfifo(myfifo1, 0666);
    //mkfifo(myfifo2, 0666);

    for(i=0; i<1; i++)
    {
        pid_t pid = fork();
        switch(pid)
        {
            case -1:
                printf("error al crear el hijo\n");
                return -1;
                break;
            case 0:
                //printf("soy el hijo %d, de PID: %d y padre: %d\n", i, getpid(), getppid());
                if (i==0)
                {
                    while (1) 
                    { 
                        // Abrimos el descriptor como escritura
                        printf("1.- Crear procesos\n");
                        printf("2.- Eliminar proceso\n");
                        printf("3.- Enviar proceso a swap\n");
                        printf("4.- Recuperar proceso de swap\n");
                        printf("5.- Mostrar tabla de memoria Logica\n");
                        printf("6.- Mostrar tabla de memoria swap\n");
                        printf("7.- Mostrar tablas de memoria fisica\n");
                        printf("0.- Salir\n");
                        printf(">> ");
                        scanf("%d", &opt);
                        analiza(opt, fd1, myfifo1);
                        system("clear");
                        if(opt == 0){
                            break;
                        }          
                    }
                    close(fd1);
                }
            default:
                if(i==0)
                {
                    wait(&status);
                    exit(0);
                }
                break;
        }
    }
    return 0; 
}