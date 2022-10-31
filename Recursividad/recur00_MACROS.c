#include<stdio.h>

#define ESCALERA1()        for(int x=i;x>0;x--){printf("\t");}i--;printf("Entrando %d \n",n);for(int x=i;x>0;x--){printf("\t");}printf("\tSaliendo 1 \n");
#define ESCALERA2()        for(int x=0;x<i;x++){printf("\t");}printf("Entrando %d \n",n);i++;
#define ESCALERA3()        for(int x=i;x>0;x--){printf("\t");}i--;printf("Saliendo %d \n",factorial);


int funcion(int n);

int main ()
{
     printf("%d\n",funcion(4));

}

int funcion(int n)
{
    int static i=0;
    int factorial=0;
    if(n==0)
    {
        ESCALERA1();
        return(1);
    }else
    {
        ESCALERA2();
        
        factorial=funcion(n-1);
        
        factorial=n*factorial;

        ESCALERA3();

        return(factorial   );
    }
}
