#include<stdio.h>
#include <unistd.h>

//kill -15 <pid>   //SIGTERM
//kill -9 <pid>   //SIGKILL no mod

//kill -19 <pid>  //SIGSTOP
//kill -18 <pid>  //SIGCONT

//kill -num `pidof eje`

int main()
{
    int i=0;
    while(1)
    {
        sleep(1);
        printf("Hola como te va %d\n ",i++);
    }
    
}
