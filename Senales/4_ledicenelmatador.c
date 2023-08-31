#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <signal.h>



int main(int argc,char * argv[])
{
    int i=0;
    if(argc==1)
    {
        printf("Olvidaste el pid del programa\n");
    }
    else
    {
        kill(atoi(argv[1]),SIGKILL);
    }
}
