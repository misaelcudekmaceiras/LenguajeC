#include<stdio.h>
#include<string.h>
struct nodo
{
    char nombre[10];
    int edad;
    struct nodo * psig;
};

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
    n1.psig=&n2;
    n2.psig=&n3;
    
    paux=pINI;//apunto paux al inicio de la lista
    
    //recorro la lista y la muestro
    while(paux!=0)
    {
    printf("nombre: %s edad: %d \n", (*paux).nombre  , (*paux).edad );
    paux=(*paux).psig;
    }
    
    
    
    
    
}
