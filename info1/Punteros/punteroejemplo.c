#include<stdio.h>
#include<stdlib.h>
void mostrame(int *);
void modificar(int *,int);
void apuntarotrolado(int * p);
	
int main(void){
	int * puntero=0;
	int variable=129;
	puntero=&variable;
	mostrame(&variable);
	printf("El valor antes de la modificacion es %d\n",*puntero);
	modificar(&variable,345);
	printf("El valor luego de la modificacion es %d\n",*puntero);
	
	apuntarotrolado(puntero);
	printf("El valor luego de la modificacion es %d\n",*puntero);
	return 0;
	} 

void mostrame(int * p){
	printf("El valor de la varibale es %d\n",*p);
	}

void modificar(int * p,int valor){
	*p=valor;
	printf("El valor asignado fue %d\n",valor);
	}
	
	void apuntarotrolado(int * p){
		p=malloc(sizeof(int));
		*p=-235;
		}
