#include<stdio.h>

void mostrar(int  m[][3]);
void llenar(int  m[][3]);

int main()
{
int matriz[3][3]={{7,8,9},{4,5,6},{1,2,3}};

mostrar(matriz);
llenar(matriz);
mostrar(matriz);


return(0);
}

void mostrar(int  m[][3])
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

void llenar(int  m[][3])
{
    for(int f=0;f<3;f++)
    {
        for(int c=0;c<3;c++)
        {
          m[f][c]=5;
        }
    }
    
}
