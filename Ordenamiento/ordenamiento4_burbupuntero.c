#include<stdio.h>

/*Esto sigue moviendo al dato en ram y no a su puntero*/

void mostrar(int *p[],int tam);
void ordBurbuja(int * v[],int tam);
int main()
{
    int * arr[10];
    //esto va a estar en memoria dinamica
    int v0=10;
    int v1=9;
    int v2=8;
    int v3=7;
    int v4=123;
    int v5=5;
    int v6=4;
    int v7=39;
    int v8=2;
    int v9=1;
    
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

void mostrar(int *p[],int tam)
{
  /*   for(int i=0;i<tam;i++)
    {
        printf("arr[%d]\t",i);
    }
*/
    printf("\n");
     for(int i=0;i<tam;i++)
    {
        printf("%d\t",*(p[i]) );
    }
    printf("\n");
     
}

void ordBurbuja(int * v[],int tam){
    int aux;
    for(int i=0;i<tam-1;i++){
        mostrar(v,tam);
        for(int j=0;j<tam-i-1;j++){
            if( (*(v[j]))> (*(v[j+1])) ){
                aux=*(v[j]);
                *(v[j])=*(v[j+1]);
                *(v[j+1])=aux;
            }
        }
    }
}
