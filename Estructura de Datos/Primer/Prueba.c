#include <stdio.h>
#include <stdlib.h>

int main (){
int n = 0;
int m = 0;
int i = 0;
int j = 0;
int **matriz;
printf ("n,m:");
scanf ("%d,%d", &n, &m);
matriz = (int**) malloc (n * sizeof(int*));
for (i = 0; i < n; i++){
matriz[i] = (int*) malloc (m * sizeof(int));
}
printf ("\nSe asigno la memoria\n");
for (i = 0; i < n; i++){
printf ("\n");
for (j = 0; j < m; j++){
printf ("\t%d", matriz[i][j]);
}
}
printf ("\n");
return 0;
}

