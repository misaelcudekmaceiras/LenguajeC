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
void enlazarNodoAlFinal(struct nodo * pinicial,struct nodo * pnodo);
void agregarNodo(struct nodo ** pinicial);
void mostrarListaEdad(struct nodo * pinicial,int edadMinima);
void borrarNodo( struct nodo ** pinicial ,int edad);
int main()
{

    struct nodo * pINI=0;//la lista esta vacia
  
    agregarNodo(&pINI);
    agregarNodo(&pINI);
    agregarNodo(&pINI);
  
    
    mostrarLista(pINI);
    printf("------\n");
  //falta corregir el pdato  borrarNodo(&pINI,3);
  //  mostrarLista(pINI);
    
    
    //falta corregir el pdato mostrarListaEdad(pINI,10);
    //falta corregir el pdato liberarLista(&pINI);
    //mostrarLista(pINI);
    
}


void borrarNodo( struct nodo ** pinicial ,int edad)
{
    struct nodo * paux=*pinicial;
    struct nodo * pant=0;
    
    if(paux==0)
    {
        printf("Lista Vacia");
    }
    else
    {
        while(paux!=0)
        {
            if(paux->edad == edad)
            {
                if(paux==*pinicial)
                {//el nodo a borrar es el primer nodo de la lista.
                    
                    if( (paux->psig) == 0)
                    {//paux es el primer Y UNICO nodo de la lista
                        *pinicial=0;//lista vacia
                        free(paux);//libero nodo a borrar
                    }
                    else
                    {//paux NO es el unico nodo de la lista, pero si es el primero
                        *pinicial=paux->psig; //apunto pINI al nuevo primer nodo 
                        free(paux);//libero nodo a borrar
                    }
                    
                }else
                {//el nodo a borrar no es el primero
                    pant->psig=paux->psig;//saltamos en el enlace de la lista al nodo a borrar
                    free(paux);//libero memoria
                }
            }
        pant=paux;    
        paux=paux->psig; 
        }
        
    }
    
}


void liberarLista(struct nodo ** pinicial)
{
    struct nodo * pactual=0;
    struct nodo * psiguiente=0;
    
    pactual=(*pinicial);
    
    while(pactual!=0){
    psiguiente=pactual->psig;
    free(pactual);
    (*pinicial)=0;
    pactual=psiguiente;
    }
    
}

void agregarNodo(struct nodo ** pinicial)
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
     //agrego nodos al enlazarNodoAlFinal
        while((paux)->psig  !=0)
        {
        (paux)=(paux)->psig; 
        }
        
        (paux)->psig=(struct nodo *) malloc(sizeof(struct nodo));//creo un nodo
        (paux)=(paux)->psig; 
        (paux)->psig=0;//hago 0 al psig del nodo creado
        (paux)->pdato   =(struct info*) malloc(sizeof(struct info));
        
        
        printf("Ingrese un nombre\n");
        scanf("%s",((paux)->pdato)->nombre);
        
        printf("Ingrese la edad\n");
        scanf("%d",  & ( ((paux)->pdato)->edad ) );
        
    }
    
    
}

void mostrarListaEdad(struct nodo * pinicial,int edadMinima)
{
    if(pinicial==0)
    {
        printf("Lista Vacia");
    }else
    {
        while(pinicial!=0)
        {
    /* printf("nombre: %s edad: %d \n", (*pinicial).nombre  , (*pinicial).edad );
        pinicial=(*pinicial).psig;*/
    if(pinicial->edad > edadMinima)
    {
    printf("nombre: %s edad: %d \n", pinicial->nombre  , pinicial->edad );    
    }
    
    
        pinicial=pinicial->psig; 
        }
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
