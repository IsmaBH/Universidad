#include "funciones.h"

int main(int argc, char const *argv[])
{
	int **matrixA = NULL;
	int **matrixB = NULL;
	int colA, rowA, colB, rowB;
	int num, m, w;
	int procNum, i, status, z, x;

	srand(time(NULL));
	printf("Ingrese el numero de columnas para la matriz A:\n");
	scanf("%d", &colA);
	printf("Ingrese el numero de filas para la matriz A:\n");
	scanf("%d", &rowA);
	printf("Ingrese el numero de columnas para la matriz B:\n");
	scanf("%d", &colB);
	printf("Ingrese el numero de procesos que desea usar:\n");
	scanf("%d", &procNum);
	rowB = colA;
	m = 0;

	/*Verificamos que sea posible hacer la multiplicacion de las matrices*/
	if (colA != rowB)
	{
		printf("El número de columnas de la primera matriz debe ser igual que el número de filas de la segunda matriz\n");
		exit(1);
	}else{
		if (procNum > rowA)
		{
			printf("No se puede realizar la operacion, el numero de procesos a usar es mayor que el numero de filas en A\n");
			exit(1);
		}else{
			/*Se asigna la memoria para las matrices A y B*/
			matrixA = Aparta_Matriz (colA, rowA);
			matrixB = Aparta_Matriz (colB, rowB);
			/*Se le asignan valores aleatorios a las matrices*/
			Llena_Matriz (matrixA, rowA, colA);
			Llena_Matriz (matrixB, rowB, colB);
			/*creamos los procesos que resolveran la multiplicacion de matrices*/
			if (procNum == rowA)
			{
				for(i=0; i<procNum; i++)
				{
					pid_t pid = fork();
					int fila[colA];
					int resultado[colB];
					int res = 0;
					switch(pid)
					{
						case -1:
							printf("error al crear el hijo\n");
							return -1;
							break;
						case 0:
							//printf("soy el hijo %d, obtuve el siguiente resultado: ", i);
							obten_Fila(matrixA, i, colA, fila);
							for (int y = 0; y < colB; ++y)
							{
								resultado[y] = Multiplica_Matrices(matrixB, y, rowB, colB, fila, res);
							}
							for (w = 0; w < colB; ++w)
							{
								printf("(%d) ", resultado[w]);
							}
							printf("\n");
							exit(0);
							break;
						default:
							if(i==procNum)
							{
								for (z = 0; z < procNum; ++z)
								{
									wait(&status);
								}
								exit(0);
							}
							break;
					}
				}
			}
			if (procNum < rowA)
			{
				for(i=0; i<procNum; i++)
				{
					pid_t pid = fork();
					int fila[colA];
					int resultado[colB];
					int res = 0;
					int aux;
					switch(pid)
					{
						case -1:
							printf("error al crear el hijo\n");
							return -1;
							break;
						case 0:
							//printf("soy el hijo %d, obtuve el siguiente resultado: ", i);
							if (i == (procNum-1))
							{
								m = i;
								aux = rowA - procNum;
								aux = aux + 1;
								for (m; m <= aux; ++m)
								{
									obten_Fila(matrixA, m, colA, fila);
									for (int y = 0; y < colB; ++y)
									{
										resultado[y] = Multiplica_Matrices(matrixB, y, rowB, colB, fila, res);
									}
									for (w = 0; w < colB; ++w)
									{
										printf("(%d) ", resultado[w]);
									}
									printf("\n");
								}
								exit(0);
								break;
							}
							else
							{
								if (i != (procNum-1))
								{
									obten_Fila(matrixA, i, colA, fila);
									for (int y = 0; y < colB; ++y)
									{
										resultado[y] = Multiplica_Matrices(matrixB, y, rowB, colB, fila, res);
									}
									for (w = 0; w < colB; ++w)
									{
										printf("(%d) ", resultado[w]);
									}
									printf("\n");
									exit(0);
									break;
								}
							}
						default:
							if(i==procNum)
							{
								for (z = 0; z < procNum; ++z)
								{
									wait(&status);
								}
								exit(0);
							}
							break;
					}
				}
			}
			/*Imprimimos las matrices para asegurar que tienen datos(Opcional)*/
			Imprime_Matriz(matrixA, rowA, colA);
			Imprime_Matriz(matrixB, rowB, colB);
		}
	}
	/*Liberamos el espacio utilizado por las matrices al finalizar*/
	free(matrixA);
	free(matrixB);
	matrixA = NULL;
	matrixB = NULL;
	return 0;
}