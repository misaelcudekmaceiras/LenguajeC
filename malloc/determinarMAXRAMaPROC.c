#include<stdio.h>
#include <stdlib.h>
/*
 * Hacer un programa que determina cuanta memoria ram puede pedir un proceso al SO
*/
int main()
{
  int * pInt=0;
  //char arr[10];//memoria se reserva cuando se ejecuta el programa
  double cont=0;
  do
  {
  pInt=(int *)malloc(1024*1024);//unidad en bytes 1MByte de memoria
cont++;  
  }while(pInt!=0);
  
  printf("La cantidad de mem ram dada fue de %f MBytes\n",cont);
  printf("La cantidad de mem ram dada fue de %f GBytes\n",(cont/1024));

  return(0);
}