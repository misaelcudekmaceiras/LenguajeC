#include<stdio.h>


enum status{on=1,off=0,error=2};
typedef enum status estado;

void prender( );
void apagar( );
void fallar( );

int main ()
{
    estado led=on;
    
/*
    switch(led)
    {
    case on: printf("encendido\n");break;
    case off:printf("apagado\n");break;
    case error:printf("Error fuera de servicio\n");break;
    default:printf("Error\n");break;
    }
*/


/*En vez de switch , array de paf */
void (*arrPaf[ 3 ])(  ) = { apagar ,prender, fallar };

    led=on;
    (*arrPaf[led])();    
    
    led=off;
    (*arrPaf[led])();    
    
    led=error;
    (*arrPaf[led])();    


return(0);
}

void prender( )
{
    printf("Prendo\n");
}
void apagar( )
{
    printf("Apago\n");
}
void fallar( )
{
    printf("Fallo\n");
}
