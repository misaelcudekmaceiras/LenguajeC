#include<stdio.h>
#include <unistd.h>
int main()
{
  int contHijo=5;
  int pidHijo=-1;
  printf("inicio del programa\n");

  while(contHijo>0)
  {
      pidHijo=fork();
      
      if(pidHijo==0)
      {//hijo
	while(1)
	{
	  printf("soy pid:%d hijo n°%d \n",getpid(),6-contHijo);
	  sleep(1);
	}
      }
      else
      {//padre
	contHijo--;
      }
    
  }
  
  printf("Fin del padre\n");

  return(0);
}
