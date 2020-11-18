#include<stdio.h>



int main (int argc, char **argv)
{
  
  FILE * fd;
  char mensaje[200];
  fd=fopen(argv[1],"r");
  
  fread(mensaje,1,sizeof(mensaje),fd);
  
  puts(mensaje);
  
  fclose(fd);
  
  return(0);
}