#include<stdio.h>
#include<stdlib.h>
void mostrar(int * array, int tam);
void llenar(int * array, int tam);
int main (void)
{
//int arr[5];
    int * arr=0;
    int tam=0;
    
    
    printf("Ingrese el tamaño deseado\n");
    scanf("%d",&tam);
    arr=malloc(sizeof(int)*tam);
    //si no hay espacio devuelve 0
  
mostrar(arr,tam);
llenar(arr,tam);
mostrar(arr,tam);


printf("Ingrese el tamaño deseado nuevamente\n");
scanf("%d",&tam);

arr=realloc(arr,sizeof(int)*tam);//redimensiono agrandar o achicar
mostrar(arr,tam);
llenar(arr,tam);
mostrar(arr,tam);

free(arr);//liberar la memoria

return 0;
}

void crearArray(????,int tam) //int **p
{
    
}

void llenar(int * array, int tam)
{
    for(int i=0;i<tam;i++)
    {
        array[i]=i*2;
    }
    //free del malloc
}

void mostrar(int * array, int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("El array tiene  en la pos %d: el valor %d: \n",i,array[i]);
    }
     printf("\n\n");
}
