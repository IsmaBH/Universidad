
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define len(x) ((int)log10(x)+1)

/* Nodo */
struct nodo{
    int valor;
    char letra;
    struct nodo *h_izquierdo,*right;
};

typedef struct nodo nodo;

/* 81 = 8.1%, 128 = 12.8% and so on. The 27th frequency is the space. Source is Wikipedia */
int frecuencias_letras [27] = {/*A*/81,/*B*/15,/*C*/28,/*D*/43,/*E*/128,/*F*/23,/*G*/20,/*H*/61,/*I*/71,/*J*/2,/*K*/1,/*L*/40,/*M*/24,/*N*/69,/*O*/76,/*P*/20,/*Q*/1,/*R*/61,/*S*/64,/*T*/91,/*U*/28,/*V*/10,/*W*/24,/*X*/1,/*Y*/20,/*Z*/1,/*ESPACIO*/130};

/*Encuentra y regresa el sub-árbol más pequeño*/
int findsmaller(nodo *array[], int differentFrom){
    int smaller;
    int i = 0;

    while (array[i]->valor==-1)
        i++;
    smaller=i;
    if (i==differentFrom){
        i++;
        while (array[i]->valor==-1)
            i++;
        smaller=i;
    }

    for (i=1;i<27;i++){
        if (array[i]->valor==-1)
            continue;
        if (i==differentFrom)
            continue;
        if (array[i]->valor<array[smaller]->valor)
            smaller = i;
    }

    return smaller;
}

/*builds the huffman tree and returns its address by reference*/
void buildHuffmanTree(nodo **tree){
    nodo *temp;
    nodo *array[27];
    int i, subTrees = 27;
    int smallOne,smallTwo;

    for (i=0;i<27;i++){
        array[i] = malloc(sizeof(nodo));
        array[i]->valor = frecuencias_letras[i];
        array[i]->letra = i;
        array[i]->h_izquierdo = NULL;
        array[i]->right = NULL;
    }

    while (subTrees>1){
        smallOne=findsmaller(array,-1);
        smallTwo=findsmaller(array,smallOne);
        temp = array[smallOne];
        array[smallOne] = malloc(sizeof(nodo));
        array[smallOne]->valor=temp->valor+array[smallTwo]->valor;
        array[smallOne]->letra=127;
        array[smallOne]->h_izquierdo=array[smallTwo];
        array[smallOne]->right=temp;
        array[smallTwo]->valor=-1;
        subTrees--;
    }

    *tree = array[smallOne];

return;
}

/* builds the table with the bits for each letra. 1 stands for binary 0 and 2 for binary 1 (used to facilitate arithmetic)*/
void fillTable(int codeTable[], nodo *tree, int Code){
    if (tree->letra<27)
        codeTable[(int)tree->letra] = Code;
    else{
        fillTable(codeTable, tree->h_izquierdo, Code*10+1);
        fillTable(codeTable, tree->right, Code*10+2);
    }

    return;
}

/*function to compress the input*/
void compressFile(FILE *input, FILE *output, int codeTable[]){
    char bit, c, x = 0;
    int n,length,bitsh_izquierdo = 8;
    int originalBits = 0, compressedBits = 0;

    while ((c=fgetc(input))!=EOF){
        originalBits++;
        if (c==32){
            length = len(codeTable[26]);
            n = codeTable[26];
        }
        else{
            length=len(codeTable[c-97]);
            n = codeTable[c-97];
        }

        while (length>0){
            compressedBits++;
            bit = n % 10 - 1;
            n /= 10;
            x = x | bit;
            bitsh_izquierdo--;
            length--;
            if (bitsh_izquierdo==0){
                fputc(x,output);
                x = 0;
                bitsh_izquierdo = 8;
            }
            x = x << 1;
        }
    }

    if (bitsh_izquierdo!=8){
        x = x << (bitsh_izquierdo-1);
        fputc(x,output);
    }

    /*print details of compression on the screen*/
    fprintf(stderr,"Original bits = %d\n",originalBits*8);
    fprintf(stderr,"Compressed bits = %d\n",compressedBits);
    fprintf(stderr,"Saved %.2f%% of memory\n",((float)compressedBits/(originalBits*8))*100);

    return;
}

/*function to decompress the input*/
void decompressFile (FILE *input, FILE *output, nodo *tree){
    nodo *current = tree;
    char c,bit;
    char mask = 1 << 7;
    int i;

    while ((c=fgetc(input))!=EOF){

        for (i=0;i<8;i++){
            bit = c & mask;
            c = c << 1;
            if (bit==0){
                current = current->h_izquierdo;
                if (current->letra!=127){
                    if (current->letra==26)
                        fputc(32, output);
                    else
                        fputc(current->letra+97,output);
                    current = tree;
                }
            }

            else{
                current = current->right;
                if (current->letra!=127){
                    if (current->letra==26)
                        fputc(32, output);
                    else
                        fputc(current->letra+97,output);
                    current = tree;
                }
            }
        }
    }

    return;
}

/*invert the codes in codeTable2 so they can be used with mod operator by compressFile function*/
void invertCodes(int codeTable[],int codeTable2[]){
    int i, n, copy;

    for (i=0;i<27;i++){
        n = codeTable[i];
        copy = 0;
        while (n>0){
            copy = copy * 10 + n %10;
            n /= 10;
        }
        codeTable2[i]=copy;
    }

return;
}

int main(){
    nodo *tree;
    int codeTable[27], codeTable2[27];
    int compress;
    char filename[20];
    FILE *input, *output;

    buildHuffmanTree(&tree);

    fillTable(codeTable, tree, 0);

    invertCodes(codeTable,codeTable2);

    /*get input details from user*/
    printf("Ingrese el nombre del archivo\n");
   scanf("%s",filename);


    input = fopen(filename, "r");
    output = fopen("output.txt","w");
    if ( input == NULL ) {
        printf("\nFile not found");
        return 0;
    }
    else
    {


printf("Type 1 to compress and 2 to decompress:\n");
    scanf("%d",&compress);
    if (compress==1){
        printf("Descomrimiendo el archivo");
        compressFile(input,output,codeTable2);
    }

    else{
        decompressFile(input,output,tree);
    }


    return 0;
}
}
