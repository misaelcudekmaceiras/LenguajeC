#include<stdio.h>

struct dato
{
    int v;
};


void mostrar(struct dato * p[],int tam);
void ordBurbuja(struct dato *  v[],int tam);
int main()
{
    struct dato * arr[10];
    //esto va a estar en memoria dinamica
    struct dato  v0;
    v0.v=10;
    struct dato  v1;
    v1.v=9;
    struct dato  v2;
    v2.v=8;
    struct dato  v3;
    v3.v=7;
    struct dato  v4;
    v4.v=123;
    struct dato  v5;
    v5.v=5;
    struct dato  v6;
    v6.v=4;
    struct dato  v7;
    v7.v=39;
    struct dato  v8;
    v8.v=2;
    struct dato  v9;
    v9.v=1;
    
    arr[0]=&v0;
    arr[1]=&v1;
    arr[2]=&v2;
    arr[3]=&v3;
    arr[4]=&v4;
    arr[5]=&v5;
    arr[6]=&v6;
    arr[7]=&v7;
    arr[8]=&v8;
    arr[9]=&v9;
    //printf("El maximo es %d \n",busMAX(arr,10));
    
    
    mostrar(arr,10);
    ordBurbuja(arr,10);
    mostrar(arr,10);
    
    
    
    return(0);
}

void mostrar(struct dato * p[],int tam)
{
  /*   for(int i=0;i<tam;i++)
    {
        printf("arr[%d]\t",i);
    }
*/
    printf("\n");
     for(int i=0;i<tam;i++)
    {
        printf("%d\t",(p[i]->v) );
    }
    printf("\n");
     
}

void ordBurbuja(struct dato * v[],int tam)
{
    struct dato * paux=NULL;
    for(int i=0;i<tam-1;i++){
        mostrar(v,tam);
        for(int j=0;j<tam-i-1;j++){
            if( ((v[j]->v))> ((v[j+1]->v)) )//comparo las informaciones
            {
                //intercambio los punteros
                paux=v[j];
                v[j]=v[j+1];
                v[j+1]=paux;
            }
        }
    }
}
