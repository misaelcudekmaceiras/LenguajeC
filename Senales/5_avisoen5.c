#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <signal.h>



void manejadorSIGALRM (int signum)
{
    printf("Pasaron 5\n");
    alarm(5);
}

int main(int argc,char * argv[])
{
    signal(SIGALRM,manejadorSIGALRM);
    alarm(5);//en 5 seg interrumpe
    while(1)
    {
        sleep(1);
        printf(".\n");
    }
}
