#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

unsigned char **Aparta_Matriz (int col, int row);
void Llena_Matriz (unsigned char ** matriz, int row, int col);
void Imprime_Matriz(unsigned char **matriz, int row, int col);
int Multiplica_Matrices(int** matrizB, int y, int rowB, int colB, int* fila, int resultado);
unsigned char administra_matriz(unsigned char** matriz, int id, int orden, int row, unsigned char *fila);