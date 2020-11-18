#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int pipe_size = 0;

void manejadorSIGNALRM (int sign) {
    printf("%d\n", pipe_size);
    exit(0);
    
}

int main (){

    int mypipe[2];
    char buffer = 2;
    
    
    pipe(mypipe);
    
    
    signal (SIGALRM, manejadorSIGNALRM);
    
    while (1){
    
        write(mypipe[1], &buffer, sizeof(buffer));
        
        pipe_size++;
        
        alarm(1);
        
    }
    
}