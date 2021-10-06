#include<stdio.h>

int funcion(int n);

int main ()
{
     printf("%d\n",funcion(4)); 

}

int funcion(int n)
{
    int static i=0;
    if(n==0)
    {
        printf("Atras %d \n",n);
        return(1);
    }else
    {
        for(int x=0;x<i;x++)
        {
        printf("\t");    
        }
        printf("Adelante %d \n",n);
        i++;
        return(n * funcion(n-1)   );
    }
}
