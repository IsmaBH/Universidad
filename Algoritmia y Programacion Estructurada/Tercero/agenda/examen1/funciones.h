#include<stdio.h>
struct corredores{
      float tiempo;
      char numero[1000];
      char nombre[80];
};
int menu();
int agregar(struct corredores *partc,int contrest);
void imprimir(struct corredores *partc,int contrest);
void ordenar(struct corredores *partc,int contrest);
