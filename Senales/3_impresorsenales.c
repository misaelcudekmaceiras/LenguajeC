#include<stdio.h>
#include <unistd.h>
#include <signal.h>

void miManejador(int signum)
{
  printf("Llego la SIGNAL %d\n",signum);
}

int main()
{
    int i=0;
    for(i=1;i<65;i++)
    {
    signal(i, miManejador);
    }

        while(1)
    {
        sleep(1);
        printf(".");
    }
    
}
