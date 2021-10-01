#include<stdio.h>
#include<stdlib.h>

void mostrar(int ** m);
void llenar(int  **m);
void llenarNumpad(int **  m);

int main()
{
//int matriz[3][3]={{7,8,9},{4,5,6},{1,2,3}};
    int numfilas=3;
    int columnas=3;
    int ** matriz=NULL;
    
    matriz=(int**)malloc((sizeof(int*))*(numfilas));//malloc para guardar el espacio de 3 int*
    for(int fila=0;fila<numfilas;fila++)
    {
        *(matriz+fila)=(int*)malloc((columnas)*sizeof(int));//en cada puntero a fila pongo un espacio de 3 int(columnas)
    }
    

mostrar(matriz);
llenar(matriz);
mostrar(matriz);
llenarNumpad(matriz);
mostrar(matriz);

//atento a esto

    for(int fila=0;fila<numfilas;fila++)
    {
        free( *(matriz+fila) );//libero cada arrayfila
    }
    
    free(matriz); //libero el arraycolumna de punteros a filas

return(0);
}

void mostrar(int ** m)
{
    printf("\n");
    for(int f=0;f<3;f++)
    {
        for(int c=0;c<3;c++)
        {
            printf("%d \t",m[f][c]);
        }
        printf("\n");
    }
    
}

void llenar(int **  m)
{
    for(int f=0;f<3;f++)
    {
        for(int c=0;c<3;c++)
        {
          m[f][c]=5;
        }
    }
    
}

void llenarNumpad(int **  m)
{
    int i=0;
    for(int f=2;f>-1;f--)
    {
        for(int c=0;c<3;c++)
        {
          *(*(m+f)+c)=++i;
        }
        
    }
    
}
