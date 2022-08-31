#include<stdio.h>

int funcion();

int main ()
{
     funcion(); 
     funcion(); 
     funcion(); 
     funcion(); 

}

int funcion()
{
    int static i=0;
    printf("%d\n",i);
    i++;
    

}
