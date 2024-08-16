#include <stdio.h>

int main (int argc, char** argv){
int i = 0;
while (i <= 255){
     printf ("%d-%c\t", i,i);
     ++i;
 }
return 0;
}
