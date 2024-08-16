#include "funciones.h"

int ** Aparta_Matriz (int col, int row)
{
  int i = 0;
  int **matriz;
  matriz = (int **)malloc(row*sizeof(int*));
	if (matriz == NULL)
	{
		perror("Hubo un error al reservar memoria");
	}
	/*Se inicia un movimiento en el arreglo para asignar memoria para las columnas de la matriz A*/
	for (int i = 0; i < row; ++i)
	{
		matriz[i] = (int*)malloc(col*sizeof(int));
		if (matriz[i] == NULL)
		{
			perror("Hubo un error al reservar memoria para las columnas");
		}
	}
  return matriz;
}

void Llena_Matriz (int ** matriz, int row, int col)
{
	int num, x, y;
	for(y = 0;y < row;y++) // esto nos movera por las filas
	{
		for(x = 0;x < col;x++) // esto nos movera por las columnas
		{
			num = rand() % 5;
			matriz[y][x] = num;
		}
	}
}

void Imprime_Matriz(int **matriz, int row, int col)
{
	int x,y;
	puts("Matriz");
	puts("-------------");
	for(y = 0;y < row;y++)
	{
		for(x = 0;x < col;x++)
		{
			fprintf(stdout,"%d\t",matriz[y][x]);
		}
		puts("\n");
	}
}

int* obten_Fila(int** matriz, int x, int colA, int *fila)
{
	for (int i = 0; i < colA; ++i)
	{
		fila[i] = matriz[x][i];
	}
	return fila;
}
int Multiplica_Matrices(int** matrizB, int y, int rowB, int colB, int* fila, int resultado)
{
	int columna[rowB];
	int parcial[rowB];
	for (int i = 0; i < rowB; ++i)
	{
		columna[i] = matrizB[i][y];
	}
	for (int i = 0; i < rowB; ++i)
	{
		parcial[i] = fila[i]*columna[i];
	}
	for (int i = 0; i < rowB; ++i)
	{
		resultado = resultado + parcial[i];
	}
	return resultado;
}