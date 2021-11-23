#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nodo
{
    char nombre[10];
    int edad;
    struct info * pdato;
    struct nodo * psig;
};

struct info
{
    char nombre[10];
    int edad;
};

void liberarLista(struct nodo ** pinicial);
void mostrarLista(struct nodo * pinicial);

void pushNodo(struct nodo ** pinicial);

void popNodo( struct nodo ** pinicial);
int main()
{

    struct nodo * pINI=0;//la lista esta vacia
  
    pushNodo(&pINI);
    pushNodo(&pINI);
    pushNodo(&pINI);
  
    mostrarLista(pINI);
    
    popNodo(&pINI);
    
    mostrarLista(pINI);
    
    popNodo(&pINI);
    
    popNodo(&pINI);
    
    liberarLista(&pINI);

    
}




void liberarLista(struct nodo ** pinicial)
{
    struct nodo * pactual=0;
    struct nodo * psiguiente=0;
    
    pactual=(*pinicial);
    
    while(pactual!=0){
    psiguiente=pactual->psig;
    free(pactual->pdato);
    free(pactual);
    (*pinicial)=0;
    pactual=psiguiente;
    }
    
}

void pushNodo(struct nodo ** pinicial)
{
    struct nodo * paux=(*pinicial);
    if((*pinicial)==0)
    {//lista vacia
     //agregar Primer Nodo
        (*pinicial)=(struct nodo *) malloc(sizeof(struct nodo));//creo un nodo
        (*pinicial)->psig=0;//hago 0 al psig del nodo creado
        (*pinicial)->pdato   =(struct info*) malloc(sizeof(struct info));
        
        
        printf("Ingrese un nombre\n");
        //scanf("%s",(*pinicial)->nombre);
        scanf("%s",((*pinicial)->pdato)->nombre);
        
    
        printf("Ingrese la edad\n");
        //scanf("%d",  & ( (*pinicial) ->edad )  );
        scanf("%d",  & ( ((*pinicial)->pdato)->edad ) );
        
    }else
    {//lista no vacia.
    //Es una pila agrego nodos al inicio SIEMPRE
        
        (paux)=(struct nodo *) malloc(sizeof(struct nodo));//creo un nodo
        
        (paux)->psig=(*pinicial); //el siguiente del 1° nuevo nodo es el 1° viejo nodo
        
        (*pinicial)=paux;//pongo al nuevo nodo como primer nodo
        
        (paux)->pdato   =(struct info*) malloc(sizeof(struct info));
        
        
        printf("Ingrese un nombre\n");
        scanf("%s",((paux)->pdato)->nombre);
        
        printf("Ingrese la edad\n");
        scanf("%d",  & ( ((paux)->pdato)->edad ) );
        
    }
    
    
}

void popNodo( struct nodo ** pinicial)
{
    struct nodo * paux;
    
    if((*pinicial)==NULL)
    {
        printf("Pila vacia nada para extraer\n");
    }
    else
    {
        paux=(*pinicial); //guardo el 1 nodo
        
        printf("Extrayendo nombre: %s edad: %d \n", ((*pinicial)->pdato)->nombre ,((*pinicial)->pdato)->edad);//extraigo dato
            
        (*pinicial)=(*pinicial)->psig; //el nuevo 1° nodo es el siguiente del actual
        
        free(paux->pdato);//libero mem del dato
        free(paux);//libero mem del nodo
        
    }
    
}

void mostrarLista(struct nodo * pinicial)
{
    if(pinicial==0)
    {
        printf("Lista Vacia");
    }else
    {
        while(pinicial!=0)
        {
    
        //printf("nombre: %s edad: %d \n", pinicial->nombre  , pinicial->edad );
        printf("nombre: %s edad: %d \n", (pinicial->pdato)->nombre ,(pinicial->pdato)->edad);
        pinicial=pinicial->psig; 
        }
    }
}



