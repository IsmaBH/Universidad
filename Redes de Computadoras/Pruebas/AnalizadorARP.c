#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
unsigned char ip[4];
unsigned char octeto;
int i = 0;

printf("Inserte Ip:");
scanf("%hhu.%hhu.%hhu.%hhu", &ip[0],&ip[1],&ip[2],&ip[3]);
printf ("\n");
for(i=0; i<=3; i++){
printf("%u", ip[i]);
}
printf("\n");
octeto = ip[3]+1;
printf("%u\n", octeto);

ip[3] = octeto;

for(i=0; i<=3; i++){
printf("%u", ip[i]);
}
printf("\n");

return 0;
}
