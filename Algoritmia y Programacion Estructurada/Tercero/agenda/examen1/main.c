#include"funciones.h"
int main(void){
struct corredores partc[1000]; //partc  participantes 
int contrest=0; //control de la estructura
int opc=0;
while(opc!=3){ //repetir hasta que la opcion 3 no sea ingresada
     opc=menu();
     switch(opc){
            case 1: 
            contrest=agregar(partc,contrest);
            break;
            case 2:
            ordenar(partc,contrest);
            imprimir(partc,contrest);
            break;
            case 3:
            break;
            default:
            printf("Ingrese una opcion correcta \n");
            break;
     }
}
return 0;
}
