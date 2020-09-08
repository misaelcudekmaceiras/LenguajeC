#include <stdio.h>


int main(){
    FILE *aFile;
  
    int num=0;;
  char cara='_';
  float pi=0;
  
  
  // Abrimos el archivo en modo lectura y binario
  aFile = fopen("informacion.dat", "rb");
  
  if(aFile == NULL){
    // En caso de no existir, le devolvemos el error
    printf("El archivo no existe");
  } else {
  
      
    // Recorremos el archivo e imprimimos lo que hay dentro
  
      // El fread recorre lo que está en la linea en la que se encuentra
      // el puntero y lo guarda en la variable info
        fread(&num, sizeof(int), 1, aFile );
        printf("int %x\n", num);
  
        fread(&cara, sizeof(char), 1, aFile );
        printf("char %c\n", cara);
        
        fread(&pi, sizeof(float), 1, aFile );
        printf("float %f\n", pi);
    
    fclose(aFile);
  }
  return 0;

} 
