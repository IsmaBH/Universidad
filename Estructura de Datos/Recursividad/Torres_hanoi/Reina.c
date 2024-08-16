//#define N  5
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define true	1
#define false	0
typedef char bool;
int N=0,K=0;
void printSolution(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool solveNQUtil(int board[N][N], int col);
bool solveNQ();
bool solveQueenafteruse();
bool solveNQbeforeuse(int board[N][N], int col);

// driver program to test above function
int main()
{
int opc,cond=1;
printf ("\t\tMenú\n\n");
printf("1.- Ingresar el número de reinas\n");
printf("2.- Salir\n");
printf ("\nElija la opción deseada: ");
scanf("%d",&opc);
switch(opc){
case 1:
system("clear");
printf("\t\tN-Reinas\n");
printf("\nIngrese el numero de reinas: ");
scanf("%d",&N);
printf ("\n\n");
solveNQ();
 while(cond==1) {

printf("\nDesea encontrar otra solución con el mismo número de reinas\n1.-Si\n2.-NO\n");
printf ("\nElija la opción deseada: ");
scanf("%d",&cond);
if(cond==1){
K++;
solveQueenafteruse();

 }
}
break;
case 2:
    printf("Gracias por usar el código");
    return 0;
    break;
}
}

/* A utility function to print solution */
void printSolution(int board[N][N])
{
    int i;
    int j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* A recursive utility function to solve N
   Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
    int i;
    usleep(1000000);
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
        return true;

    /* Consider this column and try placing
       this queen in all rows one by one */
    for (i = 0; i < N; i++)
    {
        /* Check if queen can be placed on
          board[i][col] */
        if ( isSafe(board, i, col) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
            system("clear");
            printSolution(board);

            /* recur to place rest of the queens */
            if ( solveNQUtil(board, col + 1) )
                return true;

            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = 0;
             system("clear");
            printSolution(board);// BACKTRACK
        }
    }

     /* If queen can not be place in any row in
        this colum col  then return false */
    return false;
}

/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to
   solve the problem. It returns false if queens
   cannot be placed, otherwise return true and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
bool solveNQ()
{
    int board[N][N],i,j;

    for(i = 0; i < N; i ++) { //Inicializamos el tablero
    for(j = 0; j < N; j ++) board[i][j] = 0;
}

    if ( solveNQUtil(board, 0) == false )
    {
      printf("No existe solución");
      return false;
    }

    //Si es verdadero se llama a printSolution(board);
    return true;
}

bool solveQueenafteruse()
{
    int board[N][N],i,j;

    for(i = 0; i < N; i ++) { //Inicializamos el tablero
    for(j = 0; j < N; j ++) board[i][j] = 0;
}

    if ( solveNQbeforeuse(board, 0) == false )
    {
      printf("No existe solución");
      return false;
    }

    //Si es verdadero se llama a printSolution(board);
    return true;
}

 bool solveNQbeforeuse(int board[N][N], int col)
{
    int i;
    usleep(1000000);
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
        return true;

    /* Consider this column and try placing
       this queen in all rows one by one */
    for (i = K; i < N; i++)
    {
        /* Check if queen can be placed on
          board[i][col] */
        if ( isSafe(board, i, col) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
            system("clear");
            printSolution(board);

            /* recur to place rest of the queens */
            if ( solveNQUtil(board, col + 1) )
                return true;

            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = 0;
             system("clear");
            printSolution(board);// BACKTRACK
        }
    }

     /* If queen can not be place in any row in
        this colum col  then return false */
    return false;
}

