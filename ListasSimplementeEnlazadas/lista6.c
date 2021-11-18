#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nodo
{
    char nombre[10];
    int edad;
    struct nodo * psig;
};

void mostrarLista(struct nodo * pinicial);
void enlazarNodoAlFinal(struct nodo * pinicial,struct nodo * pnodo);
void agregarNodo(struct nodo ** pinicial);
int main()
{

    struct nodo * pINI=0;//la lista esta vacia
  
    agregarNodo(&pINI);
  
    
   mostrarLista(pINI);
    
}

void agregarNodo(struct nodo ** pinicial)
{
    if((*pinicial)==0)
    {//lista vacia
     //agregar Primer Nodo
        (*pinicial)=(struct nodo *) malloc(sizeof(struct nodo));//creo un nodo
        (*pinicial)->psig=0;//hago 0 al psig del nodo creado
        printf("Ingrese un nombre\n");
        scanf("%s",(*pinicial)->nombre); // *( *(pinicial)   ).nombre =====  (*pinicial)->nombre
        printf("Ingrese la edad\n");
        scanf("%d",  & ( (*pinicial) ->edad )  );
        
    }else
    {//lista no vacia.
        
        
    }
    
    
}


void mostrarLista(struct nodo * pinicial)
{
       while(pinicial!=0)
    {
   /* printf("nombre: %s edad: %d \n", (*pinicial).nombre  , (*pinicial).edad );
    pinicial=(*pinicial).psig;*/
   printf("nombre: %s edad: %d \n", pinicial->nombre  , pinicial->edad );
    pinicial=pinicial->psig; 
    }
}



void enlazarNodoAlFinal(struct nodo * pinicial,struct nodo * pnodo)
{
    //busco el ultimo nodo
    struct nodo * pultimo=pinicial;
       
    while(pultimo->psig  !=0)
    {
    pultimo=pultimo->psig; 
    }
    
    pultimo->psig=pnodo;
    pnodo->psig=0;
    
}
