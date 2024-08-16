#include <stdio.h>

int main(){
unsigned char ip[4];
int ip_cam[4];
int i = 0;

printf("Inserte Ip:");
scanf("%hhu.%hhu.%hhu.%hhu", &ip[0],&ip[1],&ip[2],&ip[3]);
printf ("\n");
for(i=0; i<=3; i++){
printf("%u", ip[i]);
}
printf("\n");
return 0;
}
