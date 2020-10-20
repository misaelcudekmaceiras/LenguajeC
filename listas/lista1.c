#include<stdio.h>
#include<string.h>

struct dato
{
    char nombre[20];
    int edad;
    char asistencia;
    
    struct dato * psig;
};

int main()
{
    
    struct dato  p1;
    struct dato  p2;
    struct dato  p3;
    struct dato  p4;
    
    strcpy(p1.nombre,"juan");
    strcpy(p2.nombre,"pedro");
    strcpy(p3.nombre,"pablo");
    strcpy(p4.nombre,"victor");
    
    p1.edad=111;
    p2.edad=222;
    p3.edad=333;
    p4.edad=444;
    
    p1.asistencia='P';
    p2.asistencia='A';
    p3.asistencia='T';
    p4.asistencia='A';
    
    
    struct dato * pini=NULL;
    struct dato * paux=NULL;
    
    pini=&p1;
    p1.psig=&p2;
    p2.psig=&p3;   
    p3.psig=&p4;
    p4.psig=NULL;
    
    paux=pini;
    
    while(paux!=0)
    {
        printf("nombre: %s edad: %d asistencia: %c\n",paux->nombre, paux->edad, paux->asistencia);
        //paux=paux->psig;
        paux=(*paux).psig;
        
    }
    
    
    
}
