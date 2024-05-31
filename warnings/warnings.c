#include<stdio.h>
#include <stdlib.h>


int main()
{
    char numero_entero[]="123";
    char numero_float[]="123.456";

    int num_entero=0;
    float num_float=0;

    num_entero=atoi(numero_entero);
    num_float=atof(numero_float);

    printf("El entero es: %d\n",num_entero);
    printf("El float es: %f\n",num_float);



return(0);
}
