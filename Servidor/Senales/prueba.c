#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void manejadorSIGCHLD(int sig);

int main(int argc, char *argv[])
{
   int i, rc;
   
   signal(SIGCHLD, manejadorSIGCHLD);
   for (i=1; i<=4; i++)
   {
     rc = fork();
     if (rc == 0)
     {
       sleep(2);
       exit(0);
     }
   }
   while (1)
   {
     pause();
   }
}

void manejadorSIGCHLD(int sig)
{
  while (waitpid(-1, NULL, WNOHANG) != 0);
}
