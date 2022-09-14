#include<stdio.h>


enum impresora{nuevalinea='\n' ,tab='\t'};

int main ()
{
    //enum dia d1=2;
    enum impresora i1=nuevalinea;
    
    printf("%d %c",123,i1);
    i1=tab;
    printf("%d %c",123,i1);
    

return(0);
}


