#include "funciones.h"

void analiza(int opt, int fd1, char *myfifo1)
{
	char tam[4];
    char IDPROC[3];
	char estado1[6] = "1P";
    char estado2[5] = "2P";
    char estado3[2] = "3S";
    char estado4[2] = "4S";
    char estado5[2] = "5P";
    char estado6[2] = "6S";
    char estado7[2] = "7S";
	char * orden = "fin\n";
	switch(opt)
	{
		case 1:
			printf("Tamaño de memoria requerido(kbytes): ");
			scanf("%s", tam);
			//Preguntamos al administrador si hay mem disponible
			fd1 = open(myfifo1,O_WRONLY);
			//La "P" pregunta por la memoria principal
			strcat(estado1,tam);
			write(fd1, estado1, sizeof(estado1));
			//Cerramos para poder obtener una respuesta
			close(fd1);
	        break;
		case 2:
            printf("Id del proceso a Eliminar: ");
            scanf("%s", IDPROC);
            //Preguntamos al administrador si existe el proceso solicitado en RAM
            fd1 = open(myfifo1,O_WRONLY);
            //La "P" pregunta por la memoria principal
            strcat(estado2,IDPROC);
            write(fd1, estado2, sizeof(estado2));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
		case 3:
            //Preguntamos al administrador si existe el proceso solicitado en RAM
            fd1 = open(myfifo1,O_WRONLY);
            //La "S" pregunta por la memoria secundaria
            write(fd1, estado3, sizeof(estado3));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
		case 4:
            //Preguntamos al administrador si existe el proceso solicitado en RAM
            fd1 = open(myfifo1,O_WRONLY);
            //La "S" pregunta por la memoria secundaria
            write(fd1, estado4, sizeof(estado4));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
		case 5:
            //Preguntamos al administrador por el estado de las paginas
            fd1 = open(myfifo1,O_WRONLY);
            write(fd1, estado5, sizeof(estado5));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
		case 6:
            //Preguntamos al administrador por el estado de las paginas
            fd1 = open(myfifo1,O_WRONLY);
            write(fd1, estado6, sizeof(estado6));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
        case 7:
            //Pedimos que nos imprima las matrices de direcciones fisicas
            fd1 = open(myfifo1,O_WRONLY);
            write(fd1, estado7, sizeof(estado7));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
		case 0:
			fd1 = open(myfifo1,O_WRONLY);
			strcpy(str4,orden);
			write(fd1, str4, sizeof(str4));
			close(fd1);
			printf("Termine la administracion\n");
			break;
	}
}

int administra(char *str1, int fd1, char * myfifo1, lista *L, int ram)
{
	int i,k,j = 0;
	int memoria, vejez = 0; 
    int contador_swap = 0,contador_aux = 0;
    int contador_ram = 0;
    int auxV = 1, espacio_aux = 0;
    int espacio_rec = 0;
    char aux1 = 'P';
    char mem[3];
    char proc[3];
    int id_aux;
    unsigned char fila[3];
    posicion p1,p2,p3;
    elemento e1,e2;

	int packet = strlen(str1);
    char opt = str1[0];
    char tipo = str1[1];
    switch(opt)
    {
    	case '1':
            memcpy(mem, str1 + 2, 3);
            memoria = atoi(mem);    
            // Imprimimos el mensaje obtenido 
            printf("Memoria solicitada:%d\n", memoria);
            close(fd1);
            if (aux1 == tipo)
            {
                 if (memoria <= ram)
                 {
                    process++;
                 	//Aqui haria las operaciones para crear el proceso
                    p1 = First(&L[0]);
                    for (i=1;i<=Size(&L[0]);i++)
                    {
                        e1=Position(&L[0],p1);
                        if (e1.ID_PROCESO == 0)
                        {
                            contador_aux = contador_aux + e1.PAG_TAM;
                            e1.ID_MEM_FISICA = administra_matriz(Dir_RAM, process, 0, 36, fila);
                            e1.ID_PROCESO = process;
                            e1.TTL = process;
                            Replace(&L[0], p1, e1);
                            if (contador_aux >= memoria)
                            {
                                ram = ram - contador_aux;
                                printf("Creacion exitosa\n");
                                printf("RAM restante: %d\n", ram);
                                return ram;
                                break;
                            }
                        }
                        p1=Following(&L[0],p1);
                    }
                 }else{
                    printf("No hay memoria suficiente en la principal\n");
		        	printf("Haga swap de alguno de los procesos existentes\n");
		        	printf("o elimine alguno de los existentes\n");
                    return ram;
                    break;
                 }
            }
            break;
    	case '2':
            memcpy(proc, str1+2,3);
            id_aux = atoi(proc);
            close(fd1);
            //Imprimimos el ID del proceso a eliminar
            printf("Proceso a eliminar: %d\n", id_aux);
            //Aqui haria las operaciones para eliminar el proceso
            p1 = First(&L[0]);
            for (i=1;i<=Size(&L[0]);i++)
            {
                e1=Position(&L[0],p1);
                if (e1.ID_PROCESO == id_aux)
                {
                    contador_aux = contador_aux + e1.PAG_TAM;
                    administra_matriz(Dir_RAM, e1.ID_PROCESO, 1, 36, fila);
                    e1.ID_MEM_FISICA = 0;
                    e1.ID_PROCESO = 0;
                    e1.TTL = 0;
                    Replace(&L[0], p1, e1);
                }
                p1=Following(&L[0],p1);
            }
            ram = ram + contador_aux;
            printf("Se elimino con exito\n");
            printf("RAM restante: %d\n", ram);
            return ram;
    		break;
    	case '3':
            close(fd1);
            //Aqui son las operaciones para encontrar al proceso mas viejo en RAM
            etiqueta_1:
            for (k = auxV; k <= process; ++k)
            {
                p1 = First(&L[0]);
                for (i=1;i<=Size(&L[0]);i++)
                {
                    e1=Position(&L[0],p1);
                    if (e1.TTL == k)
                    {
                        vejez = e1.TTL;
                        break;
                    }
                    p1=Following(&L[0],p1);
                }
                if (vejez != 0)
                {
                    printf("Encontre al proceso: %d\n", vejez);
                    break;
                }
            }
            //Calculamos el tamaño del proceso y se pregunta si hay espacio disponible
            //dentro de la memoria SWAP
            p1 = First(&L[0]);
            for (i=1;i<=Size(&L[0]);i++)
            {
                e1=Position(&L[0],p1);
                if (e1.TTL == vejez)
                {
                    espacio_aux = espacio_aux + e1.PAG_TAM;
                }
                p1=Following(&L[0],p1);
            }
            if (espacio_aux <= swap)
            {
                //Aqui se hacen las operaciones para hacer el swapping
                p1 = First(&L[0]);
                for (i=1;i<=Size(&L[0]);i++)
                {
                    e1=Position(&L[0],p1);
                    if (e1.TTL == vejez)
                    {
                        contador_swap = contador_swap + e1.PAG_TAM;
                        p2 = First(&L[1]);
                        for (int p = 1; p <= Size(&L[1]); ++p)
                        {
                            e2=Position(&L[1],p2);
                            if (e2.ID_PROCESO == 0)
                            {
                                e2 = e1;
                                administra_matriz(Dir_RAM, e1.ID_PROCESO, 1, 36, fila);
                                e2.ID_MEM_FISICA = administra_matriz(Dir_SWAP, e1.ID_PROCESO, 0, 24, fila);
                                e1.ID_MEM_FISICA = 0;
                                e1.ID_PROCESO = 0;
                                e1.TTL = 0;
                                Replace(&L[1], p2, e2);
                                Replace(&L[0], p1, e1);
                                break;
                            }
                            p2=Following(&L[1],p2);
                        }
                    }
                    p1=Following(&L[0],p1);
                }
                swap = swap - contador_swap;
                ram = ram + contador_swap;
                printf("Se transfirio a swap el proceso: %d\n", vejez);
                printf("Memoria SWAP restante: %d\n", swap);
                return ram;
                break;
            }else{
                if (vejez < process)
                {
                    auxV = vejez+1;
                    vejez = 0;
                    espacio_aux = 0;
                    goto etiqueta_1;
                }else{
                    printf("La memoria swap no tiene suficiente capacidad\n");
                    printf("para almacenar cualquiera de los procesos existentes\n");
                    break;
                } 
            }
           break;
    	case '4':
            close(fd1);
            //Aqui son las operaciones para encontrar al proceso mas viejo en swap
            etiqueta_2:
            for (k = auxV; k <= process; ++k)
            {
                p2 = First(&L[1]);
                for (i=1;i<=Size(&L[1]);i++)
                {
                    e2=Position(&L[1],p2);
                    if (e2.TTL == k)
                    {
                        vejez = e2.TTL;
                        break;
                    }
                    p2=Following(&L[1],p2);
                }
                if (vejez != 0)
                {
                    printf("Encontre al proceso: %d\n", vejez);
                    break;
                }
            }
            //Calculamos el tamaño del proceso y se pregunta si hay espacio disponible
            //dentro de la memoria SWAP
            p2 = First(&L[1]);
            for (i=1;i<=Size(&L[1]);i++)
            {
                e2=Position(&L[1],p2);
                if (e2.TTL == vejez)
                {
                    espacio_rec = espacio_rec + e2.PAG_TAM;
                }
                p2=Following(&L[1],p2);
            }
            if (espacio_rec <= ram)
            {
                //Aqui se hacen las operaciones para hacer el swapping
                p2 = First(&L[1]);
                for (i=1;i<=Size(&L[1]);i++)
                {
                    e2=Position(&L[1],p2);
                    if (e2.TTL == vejez)
                    {
                        contador_ram = contador_ram + e2.PAG_TAM;
                        p1 = First(&L[0]);
                        for (int p = 1; p <= Size(&L[0]); ++p)
                        {
                            e1=Position(&L[0],p1);
                            if (e1.ID_PROCESO == 0)
                            {
                                e1 = e2;
                                administra_matriz(Dir_SWAP, e2.ID_PROCESO, 1, 24, fila);
                                e1.ID_MEM_FISICA = administra_matriz(Dir_RAM, e2.ID_PROCESO, 0, 36, fila);
                                e2.ID_MEM_FISICA = 0;
                                e2.ID_PROCESO = 0;
                                e2.TTL = 0;
                                Replace(&L[1], p2, e2);
                                Replace(&L[0], p1, e1);
                                break;
                            }
                            p1=Following(&L[0],p1);
                        }
                    }
                    p2=Following(&L[1],p2);
                }
                swap = swap + contador_ram;
                ram = ram - contador_ram;
                printf("Se transfirio a ram el proceso: %d\n", vejez);
                printf("Memoria RAM restante: %d\n", ram);
                return ram;
                break;
            }else{
                if (vejez < process)
                {
                    auxV = vejez+1;
                    vejez = 0;
                    espacio_aux = 0;
                    goto etiqueta_2;
                }else{
                    printf("La memoria ram no tiene suficiente capacidad\n");
                    printf("para almacenar cualquiera de los procesos existentes\n");
                    break;
                } 
            }
            break;
    	case '5':
            //Con esto imprimimos las paginas
            close(fd1);
            p1 = First(&L[0]);
            for (i=1;i<=Size(&L[0]);i++)
            {
                printf("Pagina %d en RAM:\n", i);
                e1=Position(&L[0],p1);
                printf("\tID de pagina:%d\n",e1.ID_PAGINA);
                printf("\tID de memoria fisica:%.2x\n",e1.ID_MEM_FISICA);
                printf("\tID de proceso:%d\n",e1.ID_PROCESO);
                printf("\tTTL:%d\n",e1.TTL);
                printf("\tNumero de segmento:%d\n",e1.NO_SEGMENTO);
                printf("\tTamaño de pagina:%d\n",e1.PAG_TAM);
                p1=Following(&L[0],p1);
            }
            break;
    	case '6':
            //Con esto imprimimos las paginas
            close(fd1);
            p2 = First(&L[1]);
            for (i=1;i<=Size(&L[1]);i++)
            {
                printf("Pagina %d en SWAP:\n", i);
                e2=Position(&L[1],p2);
                printf("\tID de pagina:%d\n",e2.ID_PAGINA);
                printf("\tID de memoria fisica:%.2x\n",e2.ID_MEM_FISICA);
                printf("\tID de proceso:%d\n",e2.ID_PROCESO);
                printf("\tTTL:%d\n",e2.TTL);
                printf("\tNumero de segmento:%d\n",e2.NO_SEGMENTO);
                printf("\tTamaño de pagina:%d\n",e2.PAG_TAM);
                p2=Following(&L[1],p2);
            }
            break;
        case '7':
            Imprime_Matriz(Dir_RAM, 36, 3);
            Imprime_Matriz(Dir_SWAP, 24, 3);
            break;
    }
}