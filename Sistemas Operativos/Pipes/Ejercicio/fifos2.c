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
    char * myfifo = "/tmp/myfifo";
    char * orden = "fin\n"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo, 0666); 
    char str1[80], str2[80];
    while ((strcmp(str2, orden) != 0) || (strcmp(str1, orden) != 0)) 
    { 
        // First open in read only and read 
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, 80); 
                  
        // Print the read string and close 
        printf("soy el cliente y recibi el mensaje: %s\n", str1); 
        close(fd1); 
                  
        // Now open in write mode and write 
        // string taken from user. 
        fd1 = open(myfifo,O_WRONLY); 
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    } 
    return 0;
}