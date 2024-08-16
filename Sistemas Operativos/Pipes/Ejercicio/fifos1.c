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
    int fd, i;
    int status; 
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo";
    char * orden = "fin\n";
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    mkfifo(myfifo, 0666); 
  
    char arr1[80], arr2[80];

    while ((strcmp(arr1, orden) != 0) || (strcmp(arr2, orden) != 0)) 
    { 
        // Abrimos el lado del padre para que escriba el mensaje que quiera
        fd = open(myfifo, O_WRONLY); 
              
        // Obtiene el arreglo de caracteres del usuario
        // con una longitud maxima de 80 caracteres
        fgets(arr2, 80, stdin); 
              
        // Escribimos el arreglo de caracteres en el fifo
        // y lo cerramos
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
              
        // Abrimos el fifo como solo lectura
        fd = open(myfifo, O_RDONLY); 
              
        // Leemos la entrada del Fifo 
        read(fd, arr1, sizeof(arr1)); 
              
        // Imprimimos el mensaje obtenido
        printf("Soy el servidor y recibi el mensaje: %s\n", arr1); 
        close(fd); 
    } 
    return 0; 
} 