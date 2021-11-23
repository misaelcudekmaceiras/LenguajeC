#include<stdio.h>
#include <stdio_ext.h>
#include<stdlib.h>
#include<string.h>
struct nodo
{
   // char nombre[10];
    //int edad;
    struct info * pdato;
    struct nodo * psig;
    struct nodo * pant;
};

struct info
{
    char nombre[10];
    int edad;
};

void liberarLista(struct nodo ** pinicial);
void mostrarLista(struct nodo * pinicial);
void insertarNodo(struct nodo ** pinicial,struct nodo ** pfinal);
void extraerNodo(struct nodo ** pfinal);

int main()
{

    struct nodo * pINI=0;//la cola esta vacia
    struct nodo * pFIN=0;//la cola esta vacia
  
    insertarNodo(&pINI,&pFIN);
    insertarNodo(&pINI,&pFIN);
    insertarNodo(&pINI,&pFIN);
  
    mostrarLista(pINI);//notar que se muestra al reves porque los datos se van agregando al principio

    //o guardo el fin o lo busco cada vez
    extraerNodo(&pFIN);
    
    mostrarLista(pINI);
    
    extraerNodo(&pFIN);
    insertarNodo(&pINI,&pFIN);
    
    mostrarLista(pINI);
    
    liberarLista(&pINI);
    
    printf("Gracias por suscribirse y compartir  MiT Lomas \n");
    
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

void insertarNodo(struct nodo ** pinicial,struct nodo ** pfinal)
{
    struct nodo * paux=NULL;
    if((*pinicial)==0)
    {//lista vacia
     //agregar Primer Nodo
        (*pinicial)=(struct nodo *) malloc(sizeof(struct nodo));//creo un nodo
        (*pfinal)=(*pinicial);//primer y unico nodo de la lista pini y pfin apuntan al mismo lugar
        
        (*pinicial)->psig=0;//hago 0 al psig del nodo creado
        (*pinicial)->pant=0;//hago 0 al pant del nodo creado
        (*pinicial)->pdato   =(struct info*) malloc(sizeof(struct info));
        
        
        printf("Ingrese un nombre\n");
        //scanf("%s",(*pinicial)->nombre);
        scanf("%s",((*pinicial)->pdato)->nombre);
        
    
        printf("Ingrese la edad\n");
        //scanf("%d",  & ( (*pinicial) ->edad )  );
        scanf("%d",  & ( ((*pinicial)->pdato)->edad ) );
        
    }else
    {
        //lista no vacia agrego nodo al inicio siempre pq es una cola
        paux=(struct nodo *) malloc(sizeof(struct nodo));//creo un nodo
        (paux)->psig=(*pinicial);//el nuevo primer nodo tiene como siguiente al viejo primer nodo
        
        (*pinicial)->pant=paux;//el anterior del viejo primer nodo es el nuevo primer nodo
        
        (*pinicial)=paux;//el nuevo nodo de la lista es el primer nodo actual
        //el pfinal quedo apuntando al viejo primer nodo....ultimo nodo hasta que se extraiga
        
        (*pinicial)->pdato=(struct info*) malloc(sizeof(struct info));//creo espacio para el dato
        
        printf("Ingrese un nombre\n");
        //scanf("%s",(*pinicial)->nombre);
        scanf("%s",((*pinicial)->pdato)->nombre);
        __fpurge(stdin);
    
        printf("Ingrese la edad\n");
        //scanf("%d",  & ( (*pinicial) ->edad )  );
        scanf("%d",  & ( ((*pinicial)->pdato)->edad ) );
        
        
    }

    
    
}

void extraerNodo(struct nodo ** pfinal)
{
    struct nodo * paux=NULL;
    if(*pfinal==NULL)
    {
        printf("Cola Vacia\n");
    }else
    {
        printf("Extrayendo nombre: %s edad: %d \n", ((*pfinal)->pdato)->nombre ,((*pfinal)->pdato)->edad);//extraigo dato
        paux=(*pfinal);//backup para luego liberar memoria
        (*pfinal)=(*pfinal)->pant; //el nuevo pfinal es el nuevo ultimo nodo.
        (*pfinal)->psig=NULL;//el nuevo siguiente del nuevo ultimo nodo es NUL
        
        free(paux->pdato);//libero info
        free(paux);//libero nodo
    }
    
    
}


void mostrarLista(struct nodo * pinicial)
{
    printf("____Lista____ \n");
    if(pinicial==0)
    {
        printf("Lista Vacia\n");
    }else
    {
        while(pinicial!=0)
        {
    
        //printf("nombre: %s edad: %d \n", pinicial->nombre  , pinicial->edad );
        printf("nombre: %s edad: %d \n", (pinicial->pdato)->nombre ,(pinicial->pdato)->edad);
        pinicial=pinicial->psig; 
        }
    }
    printf("\n");
}

