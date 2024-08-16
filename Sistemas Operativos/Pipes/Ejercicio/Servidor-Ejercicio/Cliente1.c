/*Soy el cliente*/
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main(int argc, char const *argv[])
{
    int fd1; 
  
    // FIFO file path 
    char * myfifo1 = "/tmp/myfifo1";
    char * orden = "fin\n"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo1, 0666); 
    char str1[80], str2[80];
    while ((strcmp(str2, orden) != 0) || (strcmp(str1, orden) != 0)) 
    { 
        // Abrimos el lado del padre para que escriba el mensaje que quiera
        fd1 = open(myfifo1, O_WRONLY); 
              
        // Obtiene el arreglo de caracteres del usuario
        // con una longitud maxima de 80 caracteres
        fgets(str2, 80, stdin); 
              
        // Escribimos el arreglo de caracteres en el fifo
        // y lo cerramos
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
              
        // Abrimos el fifo como solo lectura
        fd1 = open(myfifo1, O_RDONLY); 
              
        // Leemos la entrada del Fifo 
        read(fd1, str1, sizeof(str1)); 
              
        // Imprimimos el mensaje obtenido
        printf("Soy el cliente 1 y recibi el mensaje: %s\n", str1); 
        close(fd1);
    } 
    return 0;
}