#include<stdio.h>

void imprimirArray(int arr[],int tam);

int main()
{
    int vector[]=  {4,8,3,6,1};
    //int vector[]=  {1,2,3,4,5};
    //int vector[]=  {5,4,3,2,1};
    int min=vector[0];
    int max=vector[0];
    int aux=0;
    int x=0;

for(;x!=1;)    
    {
        x=1;
    for(int i=0;i<5-1;i++)
        {
        if(vector[i]>vector[i+1])
        {
            aux=vector[i+1];
            vector[i+1]=vector[i];
            vector[i]=aux;
            x=0;
        }
        imprimirArray(vector,5);
        }
        printf("Fin For interno\n");
    }





}

void imprimirArray(int arr[],int tam)
{
for(int i=0;i<tam;i++)
{
    printf("%d\t",arr[i]);
}
printf("\n");    
    
    
    
    
}
