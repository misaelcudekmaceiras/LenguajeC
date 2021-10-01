/*matrices*/
#include <stdio.h>

int main()
{

   char matriz[ 3 ][ 3 ] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

   int indicefila=0,indicecolumna=0;
   
   
   
      for(indicefila=0;indicefila<3;indicefila++)
      {
        for(indicecolumna=0;indicecolumna<3;indicecolumna++)
            {
            printf(" %c ",matriz[indicefila][indicecolumna]);
            }
        printf("\n");//solo para saltar de renglon al fin de una fila
      }
  
  printf("\n");
  printf("\n");
   
   
      for(indicefila=0;indicefila<3;indicefila++) 
      {
            for(indicecolumna=0;indicecolumna<3;indicecolumna++)
            {
            matriz[indicefila][indicecolumna]=indicefila;
            }
        }
   
   
   for(indicefila=0;indicefila<3;indicefila++)
   {
     for(indicecolumna=0;indicecolumna<3;indicecolumna++)
     {
	  printf(" %c ",matriz[indicefila][indicecolumna]);
     }
     printf("\n");//solo para saltar de renglon al fin de una fila
  }
  
  printf("\n");
  printf("\n");

  printf("%ld\n",sizeof(matriz));
  printf("%ld\n",sizeof(matriz[0]));
  printf("%ld\n",sizeof(matriz[0][0]));
  printf("\n");printf("\n");
      
     for(indicefila=0;indicefila<3;indicefila++)
     {
  printf("La posicion de comienzo de la fila %d  es  %p\n",indicefila,matriz[indicefila]);
       }
       
  printf("\n");printf("\n");
  
     for(indicefila=0;indicefila<3;indicefila++)
     {
        for(indicecolumna=0;indicecolumna<3;indicecolumna++)
        {
        printf("La pos de mem del  (%d,%d) es %p |\t",indicefila,indicecolumna,&matriz[indicefila][indicecolumna]);
        }
        printf("\n");//solo para saltar de renglon al fin de una fila
     }
  
   return 0; /* indica terminación exitosa */

} /* fin de main */


