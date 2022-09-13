#include<stdio.h>
#include<string.h>

//Macros

#define suma(A,B) A+B
#define menu() printf("0:Salir 1:Cargar 2:Borrar 3:Guardar\n");
#define matri(f,c)  for(int i=0;i<f;i++)\
{for(int j=0;j<c;j++)\
{printf("%d %d\t",i,j);}printf("\n"); }  


int main ()
{
    printf("%d \n",suma(4,3));
    menu();
    matri(3,3);
}


