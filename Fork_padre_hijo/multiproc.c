#include<stdio.h>
#include <unistd.h>
int main()
{
  int pid=-1;
  printf("Inicio del programa\n");
  
  pid=fork();//duplica el proceso existente
  if(pid>0)
  {//proceso padre
    printf("Soy tu padre\n");
  }
  
  if(pid==0)
  {//proceso hijo
    printf("Soy tu hijo\n");
  }
  
  printf("fin del programa\n");
  return(0);
}