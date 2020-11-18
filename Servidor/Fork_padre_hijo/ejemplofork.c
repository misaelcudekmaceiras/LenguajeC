#include<stdio.h>
#include <unistd.h>
int main()
{
  int num=0;
  
  printf("inicio del programa\n");
  switch(fork())
  {
    case -1:printf("error\n");break;
    case 0:printf("Soy tu hijo\n");
	    while(num<20)
	    {
	      printf("PID:%d hijo %d \n",getpid(),++num);
	    }
	    break;
    default : printf("Soy tu padre\n");
	      while(num>-20)
	    {
	      printf("PID:%d padre %d \n",getpid(),--num);
	    }
	      break;
  }
  return(0);
}
