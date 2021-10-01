#include<stdio.h>
#include<stdlib.h>

int main (void){

   int * pentero=0;

   pentero=malloc(sizeof(int));

   printf("Ingrese un numero\n");
   scanf("%d",pentero);
   printf("Mostrar numero %d\n",*pentero);
  
   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
   free(pentero);//No olvidar
  
  


return 0;
}
