#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
void controladorSIGUSR1(int signbr)
{
  printf("Llego SIGUSR1\n");
}
void controladorSIGINT(int signbr)
{
  printf("Llego SIGINT\n");
}
void controladorSIGUSR2(int signbr)
{
  printf("Llego SIGUSR2. SIGINT ahora tiene el comportamiento default.\n");
  signal(SIGINT, SIG_DFL);
}
int main(int argc, char *argv[])
{
  signal(SIGUSR1, controladorSIGUSR1);
  signal(SIGINT, controladorSIGINT);
  signal(SIGUSR2, controladorSIGUSR2);
  for(;;)
  {
    pause();
  }
}
