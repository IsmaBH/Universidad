#include "TADListaDoblementeLigada.h"
#define TAM 500

//Estructura de una Tabla Hash Abierta(No modificar)
typedef struct tabla_hash
{
	lista nivel[TAM];
}tabla_hash;

void Cargar_archivo (tabla_hash * t, char *ruta_a_leer);
void InitializeHash(tabla_hash *t);
void DestroyHash(tabla_hash *t);
int Hash(char *p);
void AddInHash(tabla_hash *t, elemento e, int clave);
posicion SearchInHash(tabla_hash *t, char *p, int* contador);
void DeleteInHash(tabla_hash *t, char *p, int* contador);
void ReplaceInHash(tabla_hash *t, char *p, elemento e1, int* contador);
int leecad_archivo(char *cad, int n, FILE *archivo);
void leecad(char *cad, int n);
void Stats (tabla_hash *t, char* p);
