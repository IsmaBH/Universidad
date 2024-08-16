/*Soy el cliente*/
#include "funciones.h"
#define NUM_LISTAS 2

int main(int argc, char const *argv[])
{
    int fd1, rowA, rowB, col, i;
    int ram = 144;
    swap = 96;
    process = 0;
    Dir_RAM = NULL;
    Dir_SWAP = NULL;
    // FIFO file path 
    char * myfifo1 = "/tmp/myfifo1";
    char * orden = "fin\n";
    
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo1, 0666);
    //Inicializamos las varibles para la lista de paginas
    lista L[NUM_LISTAS];
    elemento e1,e2;
    //Usamos la funcion para inicializarla
    for(i=0;i<NUM_LISTAS;i++)
    {
        Initialize(&L[i]);
    }
    //Asignamos los valores iniciales a las paginas de la RAM
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j < 6; ++j)
        {
            e1.ID_PAGINA = j;
            e1.ID_MEM_FISICA = 0;
            e1.ID_PROCESO = 0;
            e1.TTL = 0;
            e1.NO_SEGMENTO = i;
            e1.PAG_TAM = 4;
            Add(&L[0],e1);
        }
    }
    //Asignamos los valores iniciales a las paginas de la SWAP
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < 6; ++j)
        {
            e2.ID_PAGINA = j;
            e2.ID_MEM_FISICA = 0;
            e2.ID_PROCESO = 0;
            e2.TTL = 0;
            e2.NO_SEGMENTO = i;
            e2.PAG_TAM = 4;
            Add(&L[1],e2);
        }
    }
    //Generamos las tablas de direcciones fisicas de la RAM y SWAP
    col = 3;
    rowA = 36;
    rowB = 24;
    Dir_RAM = Aparta_Matriz (col, rowA);
    Dir_SWAP = Aparta_Matriz (col, rowB);
    Llena_Matriz (Dir_RAM, rowA, col);
    Llena_Matriz (Dir_SWAP, rowB, col);
    while ((strcmp(str1, orden) != 0) || (strcmp(str2, orden) != 0)) 
    { 
        // Abrimos el fifo como solo lectura
        fd1 = open(myfifo1, O_RDONLY);      
        // Leemos la entrada del Fifo 
        read(fd1, str1, sizeof(str1));
        if ((strcmp(str1,orden)) != 0)
        {
            ram = administra(str1, fd1, myfifo1, L, ram);
        }else{
            //Destruir las listas
            for(i=0;i<NUM_LISTAS;i++)
            {
                Destroy(&L[i]);
            }
            break;
        }
    }
    system("clear");
    return 0;
}