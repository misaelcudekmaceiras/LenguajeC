#include<stdio.h>

int funcion(int n);

int main ()
{
     printf("%d\n",funcion(4)); 

}

int funcion(int n)
{
    int static i=0;
    int factorial=0;
    if(n==0)
    {
        for(int x=i;x>=0;x--)
        {
        printf("\t");    
        }
        
        i--;
        printf("Saliendo %d \n",n);
        return(1);
    }else
    {
        for(int x=0;x<i;x++)
        {
        printf("\t");    
        }
        printf("Entrando %d \n",n);
        
        i++;
        
        factorial=funcion(n-1);
        
        factorial=n*factorial;
        for(int x=i;x>0;x--)
        {
        printf("\t");    
        }
        
        i--;
        
        printf("Saliendo %d \n",factorial);
        return(factorial   );
    }
}
