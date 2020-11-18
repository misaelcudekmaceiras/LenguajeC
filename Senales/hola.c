#include<stdio.h>
#include <unistd.h>


int main()
{
    int i=0;
    while(1)
    {
        sleep(1);
        printf("Hola como te va %d\n ",i++);
    }
    
    
}
