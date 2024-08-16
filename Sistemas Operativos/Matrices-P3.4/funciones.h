#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int **Aparta_Matriz (int col, int row);
void Llena_Matriz (int ** matriz, int row, int col);
void Imprime_Matriz(int **matriz, int row, int col);
int Multiplica_Matrices(int** matrizB, int y, int rowB, int colB, int* fila, int resultado);
int* obten_Fila(int** matriz, int x, int colA, int *fila);