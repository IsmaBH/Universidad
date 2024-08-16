#include "matrices.h"

unsigned char ** Aparta_Matriz (int col, int row)
{
  int i = 0;
  unsigned char **matriz;
  matriz = (unsigned char **)malloc(row*sizeof(unsigned char*));
	if (matriz == NULL)
	{
		perror("Hubo un error al reservar memoria");
	}
	/*Se inicia un movimiento en el arreglo para asignar memoria para las columnas de la matriz A*/
	for (int i = 0; i < row; ++i)
	{
		matriz[i] = (unsigned char*)malloc(col*sizeof(unsigned char));
		if (matriz[i] == NULL)
		{
			perror("Hubo un error al reservar memoria para las columnas");
		}
	}
  return matriz;
}

void Llena_Matriz (unsigned char ** matriz, int row, int col)
{
	srand(time(NULL));
	int LEN, x, y;
	LEN = 6;
	unsigned char direccion[LEN];
	unsigned char ID = 0x00;
	unsigned char flag = 0x00;
	memset(direccion, 1, LEN);
	//Esta parte llena los ID de la memoria
	x = 0;
	for (y = 0; y < row; ++y)
	{
		matriz[y][x] = ID++;
	}
	//Este for llenara las direciones fisicas de la tabla
	x = 1;
	for(y = 0;y < row;y++)
	{
		if (row == 36)
		{
			for (int i = 0; i < LEN-1; ++i)
			{
				direccion[i] = (unsigned char)(rand()%(421-250)+1);
			}
		}else{
			for (int i = 0; i < LEN-1; ++i)
			{
				direccion[i] = (unsigned char)(rand()%(800-422)+1);
			}
		}
		direccion[LEN-1] = 0;
		matriz[y][x] = *direccion;
	}
	//Esta parte llenara la columna de flags
	x = 2;
	for (y = 0; y < row; ++y)
	{
		matriz[y][x] = flag;
	}
}

void Imprime_Matriz(unsigned char **matriz, int row, int col)
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

unsigned char administra_matriz(unsigned char** matriz, int id, int orden, int row, unsigned char *fila)
{
	int x,y;
	if (orden == 0)
	{
		x = 2;
		for (int i = 0; i < row; ++i)
		{
			if (matriz[i][x] == 0x00)
			{
				matriz[i][x] = id;
				y = i;
				break;
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			fila[i] = matriz[y][i];
		}
		return fila[0];
	}
	if (orden != 0)
	{
		x = 2;
		for (int i = 0; i < row; ++i)
		{
			if (matriz[i][x] == id)
			{
				matriz[i][x] = 0x00;
				y = i;
				break;
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			fila[i] = matriz[y][i];
		}
		return fila[0];
	}
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