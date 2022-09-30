#include<stdio.h>
#include<string.h>

https://www.h-schmidt.net/FloatConverter/IEEE754.html

struct mifloat
{
    unsigned int mantisa:23;
    unsigned int exponente:8;
    unsigned int signo:1;
};

union floatformat
{
float num;
struct mifloat floatformateado;

};


int main()
{

    union floatformat float1;
    
    float1.num=1;
    printf("float %f\n",float1.num);
    printf("Signo: %d\n",float1.floatformateado.signo);
    printf("Exponete: %d\n",float1.floatformateado.exponente);
    printf("Mantisa: %d\n\n",float1.floatformateado.mantisa);
    
    float1.num=-1;
    printf("float %f\n",float1.num);
    printf("Signo: %d\n",float1.floatformateado.signo);
    printf("Exponete: %d\n",float1.floatformateado.exponente);
    printf("Mantisa: %d\n\n",float1.floatformateado.mantisa);
    
    float1.num=1.5;
    printf("float %f\n",float1.num);
    printf("Signo: %d\n",float1.floatformateado.signo);
    printf("Exponete: %d\n",float1.floatformateado.exponente);
    printf("Mantisa: %d\n\n",float1.floatformateado.mantisa);
    
    float1.num=-1.5;
    printf("float %f\n",float1.num);
    printf("Signo: %d\n",float1.floatformateado.signo);
    printf("Exponete: %d\n",float1.floatformateado.exponente);
    printf("Mantisa: %d\n\n",float1.floatformateado.mantisa);
    
    
    float1.num=64.5;
    printf("float %f\n",float1.num);
    printf("Signo: %d\n",float1.floatformateado.signo);
    printf("Exponete: %d\n",float1.floatformateado.exponente);
    printf("Mantisa: %d\n\n",float1.floatformateado.mantisa);
    
    float1.num=-128.5;
    printf("float %f\n",float1.num);
    printf("Signo: %d\n",float1.floatformateado.signo);
    printf("Exponete: %d\n",float1.floatformateado.exponente);
    printf("Mantisa: %d\n\n",float1.floatformateado.mantisa);
    
    
    



return(0);
}

