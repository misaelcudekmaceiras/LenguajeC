#include<stdio.h>


enum dia{lunes,martes,miercoles,jueves,viernes,sabado,domingo};

int main ()
{
    //enum dia d1=2;
    enum dia d1=miercoles;
    
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


