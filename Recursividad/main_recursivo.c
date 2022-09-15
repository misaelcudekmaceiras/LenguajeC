#include<stdio.h>
#include<math.h>
//Todavia no funciona correcto, pero .. pasa a binario la cantidad de argumentos ingresados 
//se compila con  gcc -o eje main_recursivo.c -lm

int main (int argc, char ** argv)

{   static int cifras=0;
    char * ar[]={" "," "};
    int result=0;
    if(argc==1)
    {
        cifras++;

        return(argc*pow(10,cifras-1));
    }else
    {   
        result=argc%2;
        argc=argc/2;

        cifras++;
        return(result*pow(10,cifras-1) + main(argc,ar) );
    }

}


