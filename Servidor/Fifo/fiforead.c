#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main ()
{ 
  int fd1;
  char buf [100]; 
  fd1 = open ( "mitubito", O_RDONLY );
  read ( fd1, buf, 100 );
  printf ( "%s\n", buf );
  close (fd1);
} 
