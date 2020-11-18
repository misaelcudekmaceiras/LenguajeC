#include<stdio.h>
#include<string.h>


int main (int argc, char **argv)
{
  
  FILE * fd;
  char mensaje[]="Hola estoy escribiendo";
  fd=fopen(argv[1],"w");
  
  fwrite(mensaje,1,strlen(mensaje),fd);
  
  
  fclose(fd);
  
  return(0);
}