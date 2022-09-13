#include<stdio.h>


enum status{on=1,off=0,error=2};
typedef enum status estado;

int main ()
{
    estado led=on;
    estado led2=5;//Notar no es error sintactico, no se deberia hacer asignacion
                  //Sino usar las etiquetas

    switch(led)
    {
    case on: printf("encendido\n");break;
    case off:printf("apagado\n");break;
    case error:printf("Error fuera de servicio\n");break;
    default:printf("Error\n");break;
    }
    
    switch(led2)
    {
    case on: printf("encendido\n");break;
    case off:printf("apagado\n");break;
    case error:printf("Error fuera de servicio\n");break;
    default:printf("Error\n");break;
    }
return(0);
}


