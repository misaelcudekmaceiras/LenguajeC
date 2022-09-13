#include<stdio.h>


enum status{on=1,off=0,error=2};
typedef enum status estado;

int main ()
{
    estado led=on;
    

    switch(led)
    {
    case on: printf("encendido\n");break;
    case off:printf("apagado\n");break;
    case error:printf("Error fuera de servicio\n");break;
    default:printf("Error\n");break;
    }
return(0);
}


