#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int crea_hijos(int l,int i,int x);

int main(){
	int x=2;
	int status,i,l,x2;
	printf("Nivel a alcanzar: \n");
	scanf("%d",&l);
	if(l==0){
		printf("estamos en el nivel %d \n",l);
		printf("el padre es %d\n",getpid());
	}
	else if(l>0){
		x2=0;
		printf("estamos en el nivel %d \n",x2);	
		printf("el padre es %d\n",getpid());
		x2=1;
		printf("estamos en el nivel %d \n",x2);	
	for(i=0;i<2;i++){

		pid_t pid = fork();
		switch(pid){
			case 0:
				sleep(3);
				printf("soy el hijo de ID %d. Mi padre es %d \n",getpid(),getppid());
				if(l>1){
					if(i==0){
						x2=2;
						printf("estamos en el nivel %d \n",x2);	
					}
					crea_hijos(l,i, x);
					exit(0);
				}
				else{
					exit(0);
				}				
			break;
			case -1:
				printf("error al crear el hijo\n");
				return -1;
			break;
			default:
			if(i==1){
				wait(&status);
				wait(&status);
			}
			break;
		}
	}
	}
	else if(l<0){
		printf("no se aceptan carecteres negativos\n");
	}
}

int crea_hijos(int l,int i,int x){
	int status,n,k,w;
	if(i==0){
		n=3;
	}
	else if(i==1){
		n=4;
	}

	for(k=0;k<n;k++){
		pid_t pid = fork();

		switch(pid){
			case 0:
				//sleep(3);
				printf("soy el hijo de ID %d. Mi padre es %d \n",getpid(),getppid());
				//sleep(6);
				if(l>x){
					if(i==0){
						if(k==0){
							x = x + 1;
							printf("estamos en el nivel %d \n",x);
						}
					}
				crea_hijos(l-1,i,x);
				exit(0);
				}
				else{
					exit(0);
				}
			break;
			case -1:
				printf("error al crear el hijo\n");
				return -1;
			break;
			default:
			if(k==(n-1)){
				for(w=0;w<=n;w++){
					wait(&status);
				}
			}
			break;
		}
	}
}