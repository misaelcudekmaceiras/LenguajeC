#include<stdio.h>
#include<stdlib.h>
void mostrar(int * array, int tam);
void llenar(int * array, int tam);
int main (void)
{
int arr[5];
  
mostrar(arr,5);
llenar(arr,5);
mostrar(arr,5);

return 0;
}
void llenar(int * array, int tam)
{
    for(int i=0;i<tam;i++)
    {
        array[i]=i*2;
    }
}

void mostrar(int * array, int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("El array tiene  en la pos %d: el valor %d: \n",i,array[i]);
    }
     printf("\n\n");
}
