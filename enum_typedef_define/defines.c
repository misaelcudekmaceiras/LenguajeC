#include<stdio.h>
#include<string.h>

#define valor 123
#define estado "OK"
#define peso 85.5

int main ()
{
    int a=0;
    char cadena[10];
    float b=0;
    
    a=valor;
    strcpy(cadena,estado);
    b=peso;
    
    printf("%d\n ",a);
    printf("%s\n",cadena);
    printf("%f\n",b);

}


