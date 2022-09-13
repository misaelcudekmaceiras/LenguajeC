#include<stdio.h>


enum dia{lunes=1,martes,miercoles,jueves,viernes,sabado,domingo=0};

int main ()
{
    enum dia d1=viernes;
    
    switch(d1)
    {
    case lunes: printf("Hoy es LUNES y es un buen dia para programar\n");break;
    case martes:printf("Hoy es MARTES y es un buen dia para programar\n");break;
    case miercoles:printf("Hoy MIERCOLES es y es un buen dia para programar\n");break;
    case jueves:printf("Hoy es JUEVES y es un buen dia para programar\n");break;
    case viernes:printf("Hoy es VIERNES y es un buen dia para programar\n");break;
    case sabado:printf("Hoy es SABADO y es un buen dia para programar\n");break;
    case domingo:printf("Hoy es DOMINGO y es un buen dia para programar\n");break;
    default:printf("Dia invalido y es un buen dia para programar\n");break;
    }
return(0);
}


