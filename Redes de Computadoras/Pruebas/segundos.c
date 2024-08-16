#include <stdio.h>
#include <sys/time.h>

int main(){

int a = 10, b = 10;
int tam, bandera = 0;
struct timeval start, end;
long mtime = 0, seconds, useconds;

gettimeofday(&start, NULL);
while(mtime < 1000){
if((a+b) == 20){
printf("Ya salio :(");
}
else{
printf ("Hola soy un mensaje de 1 segundo :D\n");
bandera = 1;
}
gettimeofday(&end, NULL);
seconds = end.tv_sec - start.tv_sec;
useconds = end.tv_usec - start.tv_usec;
mtime = ((seconds)*1000 + useconds/1000.0)+0.5;
if (bandera == 1)
break;
}
printf("Elapsed time: %ld miliseconds\n", mtime);
return 0;
}
