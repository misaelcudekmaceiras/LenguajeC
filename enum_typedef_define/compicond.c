#include<stdio.h>

#define debug 123
//No importa valor

int main ()
{
    
    printf("Inicio del programa\n");
    
#ifdef debug
    printf("Debuggeo esta parte del codigo\n");
#endif
    
    printf("Fin del programa\n");

}


