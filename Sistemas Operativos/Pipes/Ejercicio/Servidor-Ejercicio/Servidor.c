/*Soy el Servidor*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
  
int main() 
{ 
    int fd1, fd2, fd3, i;
    int status;
  
    // FIFO file path 
    char * myfifo1 = "/tmp/myfifo1";
    char * myfifo2 = "/tmp/myfifo2";
    char * myfifo3 = "/tmp/myfifo3";
    char * orden = "fin\n";
    char * bot = "Soy una respuesta automatica del servidor desde el hijo con PID: ";
    char sh[5];
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);
    mkfifo(myfifo3, 0666); 
  
    char arr1[80], arr2[80];

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
                //printf("soy el hijo %d, de PID: %d y padre: %d\n", i, getpid(), getppid());
                if (i==0)
                {
                    while ((strcmp(arr1, orden) != 0) || (strcmp(arr2, orden) != 0)) 
                    { 
                        // Primero abrimos como solo escucha
                        fd1 = open(myfifo1,O_RDONLY); 
                        read(fd1, arr1, 80); 
                                  
                        // Imprimimos lo que nos llegue
                        printf("soy el Servidor(Canal 1) y recibi el mensaje: %s\n", arr1);
                        close(fd1); 
                                  
                        // Abrimos el descriptor como escritura
                        // Respuesta automatica del servidor
                        fd1 = open(myfifo1,O_WRONLY);
                        if (strcmp(arr1, orden) == 0)
                        {
                            strcpy(arr2, orden);
                        }else{
                            strcpy(arr2, bot);
                            sprintf(sh, "%d\n", getpid());
                            strcat(arr2, sh);
                        } 
                        //fgets(str2, 80, stdin); 
                        write(fd1, arr2, strlen(arr2)+1); 
                        close(fd1); 
                    }
                    printf("Termine la comunicación con el canal 1\n");
                }
                if (i == 1)
                {
                    while ((strcmp(arr1, orden) != 0) || (strcmp(arr2, orden) != 0)) 
                    { 
                        // Primero abrimos como solo escucha
                        fd2 = open(myfifo2,O_RDONLY); 
                        read(fd2, arr1, 80); 
                                  
                        // Imprimimos lo que nos llegue
                        printf("soy el Servidor(Canal 2) y recibi el mensaje: %s\n", arr1);
                        close(fd2); 
                                  
                        // Abrimos el descriptor como escritura
                        // Respuesta automatica del servidor
                        fd2 = open(myfifo2,O_WRONLY);
                        if (strcmp(arr1, orden) == 0)
                        {
                            strcpy(arr2, orden);
                        }else{
                            strcpy(arr2, bot);
                            sprintf(sh, "%d\n", getpid());
                            strcat(arr2, sh);
                        }  
                        //fgets(str2, 80, stdin); 
                        write(fd2, arr2, strlen(arr2)+1); 
                        close(fd2); 
                    }
                    printf("Termine la comunicación con el canal 2\n");
                }
                if (i == 2)
                {
                    while ((strcmp(arr1, orden) != 0) || (strcmp(arr2, orden) != 0)) 
                    { 
                        // Primero abrimos como solo escucha
                        fd3 = open(myfifo3,O_RDONLY); 
                        read(fd3, arr1, 80); 
                                  
                        // Imprimimos lo que nos llegue
                        printf("soy el Servidor(Canal 3) y recibi el mensaje: %s\n", arr1);
                        close(fd3); 
                                  
                        // Abrimos el descriptor como escritura
                        // Respuesta automatica del servidor
                        fd3 = open(myfifo3,O_WRONLY);
                        if (strcmp(arr1, orden) == 0)
                        {
                            strcpy(arr2, orden);
                        }else{
                            strcpy(arr2, bot);
                            sprintf(sh, "%d\n", getpid());
                            strcat(arr2, sh);
                        }  
                        //fgets(str2, 80, stdin); 
                        write(fd3, arr2, strlen(arr2)+1); 
                        close(fd3); 
                    }
                    printf("Termine la comunicación con el canal 3\n");
                }
                exit(0);
                break;
            default:
                /*if (i == 0)
                {
                    printf("Soy el padre con PID: %d y padre: %d\n", getpid(), getppid());
                }*/
                if(i==2)
                {
                    for (int z = 0; z < 3; ++z)
                    {
                        wait(&status);
                    }
                    exit(0);
                }
                break;
        }
    }
    return 0; 
}