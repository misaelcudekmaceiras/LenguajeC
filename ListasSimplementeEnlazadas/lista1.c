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
    struct nodo * pINI=0;//la lista esta vacia
    struct nodo * paux=0;
    //cargo datos en nodo
    strcpy(n1.nombre,"diego");// NO nombre="diego"
    n1.edad=111;
    n1.psig=0;//NULL
    
    pINI=&n1;
    paux=pINI;//apunto paux al inicio de la lista
    while(paux!=0)
    {
    printf("nombre: %s edad: %d \n", (*paux).nombre  , (*paux).edad );
    paux=(*paux).psig;
    }
    
}
