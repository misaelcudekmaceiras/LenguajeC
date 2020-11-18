#include<stdio.h>
#include<unistd.h>
#include<signal.h>
//hacer un programa, que cree 5 procesos hijos

void manejaSIGCHLD(int e)
{
  printf("un hijo se murio ;-(\n");
}

int main()
{
  int pid=-1;
  int i=0;
  int cantHijos=5;
  signal(SIGCHLD,manejaSIGCHLD);
  printf("Inicio del programa\n");
  
  while(cantHijos>0)
  {
  if(pid!=0)
  {
    --cantHijos;
    pid=fork();//duplica el proceso existente
  }
  
  if(pid==0)
  {
    while(1)
    {
      printf("soy hijo %d %d\n",++i,getpid());
      sleep(1);
    }
  }
  
  }
  
      while(1)
    {
      printf("soy el padre  %d\n",getpid());
      sleep(1);
    }
  
  printf("fin del programa\n");
  return(0);
}