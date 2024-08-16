#include"funciones.h"
int menu(){
    int opc=0;
    printf("1) Agregar Corredores \n");
    printf("2) Imprimir Corredores \n");
    printf("3) Salir \n");
    printf("Digite la opcion: ");
    scanf("%d",&opc);
return opc;
}
int agregar(struct corredores *partc,int contrest){
     int contr=0,cont=0;
     printf("Cuantos corredores agregaras: ");
     scanf("%d",&contr);
     for(cont=0; cont<contr; cont++){
        printf("Ingrese tiempo: ");
        scanf("%f",&(partc+contrest)->tiempo);
        printf("Ingrese numero: ");
        scanf("%s",(partc+contrest)->numero);
        printf("Ingrese nombre: ");
        scanf("%s",(partc+contrest)->nombre);
        contrest++; //control de la estructura
        }
return contrest;
}
void ordenar(struct corredores *partc,int contrest){
     int cont1=0, cont2=0;
     struct corredores temp;
     for(cont1=0; cont1<contrest; cont1++){
        for(cont2=0; cont2<contrest-1; cont2++){
            if((partc+cont2)->tiempo>(partc+cont2+1)->tiempo){
               temp=*(partc+cont2);
               *(partc+cont2)=*(partc+cont2+1);
               *(partc+cont2+1)=temp;
             }
           }
         }    
return;
}
void imprimir(struct corredores *partc, int contrest){
     int cont=0;
     for(cont=0; cont<contrest; cont++){
        printf("%s ",(partc+cont)->nombre);
        printf("%.4f \n",(partc+cont)->tiempo);
        }
return;
}
