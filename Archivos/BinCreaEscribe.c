#include <stdio.h>


int main(){
  // Puntero de tipo FILE (Archivo)
  FILE *aFile;
  
  int num=0x2A3F88;
  char cara='G';
  float pi=3.14;
  
  aFile = fopen("informacion.dat", "wb");

  fwrite(&num, sizeof(num), 1, aFile);
  fwrite(&cara, sizeof(char), 1, aFile);
  fwrite(&pi, sizeof(float), 1, aFile);
  
  fclose(aFile);
  
  return 0;
}
