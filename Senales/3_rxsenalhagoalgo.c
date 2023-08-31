#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <signal.h>

void miManejadorSIGTERM(int signum)
{
  int i=10;
  printf("Llego la SIGNAL %d\n",signum);

  while(i>0)
  {
      printf("Este programa finalizara en %d segundos\n",i);
      i--;
      sleep(1);
    }
    exit(0);
}

int main()
{
    int i=0;

    signal(SIGTERM, miManejadorSIGTERM);//instalo manejadorsigterm


        while(1)
    {
        sleep(1);

        printf(".\n");
    }
    
}
