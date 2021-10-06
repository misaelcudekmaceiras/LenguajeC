#include<stdio.h>

int funcion(int n);

int main ()
{
     printf("%d\n",funcion(4)); 

}

int funcion(int n)
{
    if(n==0)
    {
        printf("Atras %d \n",n);
        return(1);
    }else
    {
        printf("Adelante %d \n",n);
        return(n * funcion(n-1)   );
    }
}
