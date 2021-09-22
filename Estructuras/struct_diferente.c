#include<stdio.h>


struct estru
{
  char c1;
  char c2;
  int num;
};

int main ()

{
  
  printf("la sumatoria de los campos vale %ld (a mi me sale 6 MVirtual32bits)\n",(sizeof(char)+sizeof(char)+sizeof(int)));
  printf("el tam de la estructura vale %ld (a mi me sale 8  MVirtual32bits)\n",sizeof(struct estru));
  
  
  
  return(0);
}