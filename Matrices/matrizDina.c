#include<stdio.h>
#include<stdlib.h>

void mostrar(int ** m,int fi,int co);
void llenar(int  **m,int fi,int co,int valor);
void llenarNumpad(int **  m);
void ampliar(int ***matri, int fi,int co,int finue, int conue);


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
    
    
    

mostrar(matriz,numfilas,columnas);
llenar(matriz,numfilas,columnas,2);
mostrar(matriz,numfilas,columnas);

ampliar(&matriz,numfilas,columnas,5,5);
llenar(matriz,5,5,5);
mostrar(matriz,5,5);


//atento a esto

    for(int fila=0;fila<numfilas;fila++)
    {
        free( *(matriz+fila) );//libero cada arrayfila
    }
    
    free(matriz); //libero el arraycolumna de punteros a filas

return(0);
}

void ampliar(int ***matri, int fi,int co,int finue, int conue)
{
    //Amplio la cantidad de el array de filas
   // printf("%p\n",*matri);
    (*matri)=realloc((*matri) , sizeof(int*)*(finue) );
    
        for(int fila=0;fila<finue;fila++)
        {
     //       printf("%p\n",*(*matri+fila));
        *(*matri+fila)=realloc( *(*matri+fila) , (conue)*sizeof(int) );    
        }
      
}

void mostrar(int ** m,int fi,int co)
{
    printf("\n");
    for(int f=0;f<fi;f++)
    {
        for(int c=0;c<co;c++)
        {
            printf("%d \t",m[f][c]);
        }
        printf("\n");
    }
    
}

void llenar(int **  m,int fi,int co,int valor)
{
    for(int f=0;f<fi;f++)
    {
        for(int c=0;c<co;c++)
        {
          m[f][c]=valor;
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
