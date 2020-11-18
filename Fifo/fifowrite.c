#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
char * phrase = "Esta es una prueba de named pipes";
int main ()
{
  int fd1;
  fd1 = open ( "mitubito", O_WRONLY );
  write (fd1, phrase, strlen ( phrase)+1 );
  close (fd1);
} 
