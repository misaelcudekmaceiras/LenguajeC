#include <stdio.h>

struct Informacion {
  char iNombre[ 15 ];
  int iPrecio;
};

int main(){
  // Puntero de tipo FILE (Archivo)
  FILE *aFile;
  
  // Creamos la info con diferentes tipos de variables
  struct Informacion info = { "", 0 };
  
  // Abrimos el archivo en modo lectura y binario
  aFile = fopen("informacion.dat", "rb");
  
  if(aFile == NULL){
    // En caso de no existir, le devolvemos el error
    printf("El archivo no existe");
  } else {
    // Imprimimos lo que hay dentro del archivo
    printf("Información:\n");
      
    // Recorremos el archivo e imprimimos lo que hay dentro
    while (feof(aFile) == 0) {
      // El fread recorre lo que está en la linea en la que se encuentra
      // el puntero y lo guarda en la variable info
      fread(&info, sizeof(struct Informacion), 1, aFile );
      
      // Para que no se mande el mensaje cuando la estructura llega al EOF
      if(feof(aFile) == 0)
		printf("%s%d\n", info.iNombre, info.iPrecio);
    }
    
    fclose(aFile);
  }
  return 0;

} 