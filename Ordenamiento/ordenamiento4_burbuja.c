#include<stdio.h>



void mostrar(int *p,int tam);
void ordBurbuja(int * v,int tam);
int main()
{
    int arr[10];
    arr[0]=10;
    arr[1]=9;
    arr[2]=8;
    arr[3]=7;
    arr[4]=123;
    arr[5]=5;
    arr[6]=4;
    arr[7]=39;
    arr[8]=2;
    arr[9]=1;
    //printf("El maximo es %d \n",busMAX(arr,10));
    
    
    mostrar(arr,10);
    ordBurbuja(arr,10);
    mostrar(arr,10);
    
    
    
    return(0);
}

void mostrar(int *p,int tam)
{
  /*   for(int i=0;i<tam;i++)
    {
        printf("arr[%d]\t",i);
    }
*/
    printf("\n");
     for(int i=0;i<tam;i++)
    {
        printf("%d\t",*(p+i));
    }
    printf("\n");
     
}

void ordBurbuja(int * v,int tam){
    int aux;
    for(int i=0;i<tam-1;i++){
        mostrar(v,tam);
        for(int j=0;j<tam-i-1;j++){
            if(*(v+j)>*(v+j+1)){
                aux=*(v+j);
                *(v+j)=*(v+j+1);
                *(v+j+1)=aux;
            }
        }
    }
}
