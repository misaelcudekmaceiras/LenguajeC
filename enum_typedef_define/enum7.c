#include<stdio.h>


enum estado{on=1,off=0,error=2};

int main ()
{
    enum estado led=on;
    

    switch(led)
    {
    case on: printf("encendido\n");break;
    case off:printf("apagado\n");break;
    case error:printf("Error fuera de servicio\n");break;
    default:printf("Error\n");break;
    }
return(0);
}


