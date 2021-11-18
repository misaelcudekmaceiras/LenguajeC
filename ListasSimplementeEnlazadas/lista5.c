#include<stdio.h>
#include<string.h>
struct nodo
{
    char nombre[10];
    int edad;
    struct nodo * psig;
};

void mostrarLista(struct nodo * pinicial);
void enlazarNodoAlFinal(struct nodo * pinicial,struct nodo * pnodo);

int main()
{
    struct nodo n1;//creo un nodo
    struct nodo n2;//creo un nodo
    struct nodo n3;//creo un nodo
    struct nodo * pINI=0;//la lista esta vacia
    struct nodo * paux=0;
    //cargo datos en nodo
    strcpy(n1.nombre,"diego");// NO nombre="diego"
    n1.edad=111;
    n1.psig=0;//NULL
    
     strcpy(n2.nombre,"misael");// NO nombre="diego"
    n2.edad=222;
    n2.psig=0;//NULL
    
    strcpy(n3.nombre,"juan");// NO nombre="diego"
    n3.edad=333;
    n3.psig=0;//NULL
    
    //creo la lista
    pINI=&n1;
    enlazarNodoAlFinal(pINI,&n2);
    //n1.psig=&n2;
    enlazarNodoAlFinal(pINI,&n3);
    //n2.psig=&n3;
    
    paux=pINI;//apunto paux al inicio de la lista
    
    //recorro la lista y la muestro
   mostrarLista(pINI);
    
    paux=&n1;
    (*paux).psig=&n3;
    
    printf("Desenganchado el nodo\n");
    
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
        scanf("%d",  &((*pinicial)->edad)  );
        
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
