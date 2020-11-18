#include<stdio.h>
#include<stdlib.h>

int main (void){
   int * pentero=0;

   pentero=malloc(1000);

  pentero=realloc(pentero,500);

   free(pentero);//No olvidar
return 0;
}
