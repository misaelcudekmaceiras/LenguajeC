#include <stdio.h>

struct Informacion {
  char iNombre[ 15 ];
  int iPrecio;
};

int main(){
  // Puntero de tipo FILE (Archivo)
  FILE *aFile;
  
  // Creamos la info con diferentes tipos de variables
  struct Informacion bebida = { "Bebida - $", 15 };
  struct Informacion comida = { "Comida - $", 25 };
  
  // Creamos el archivo o lo leemos de estar creado con fopen en modo binario
  aFile = fopen("informacion.dat", "wb");
  
  // Lo escribimos dentro del archivo con fwrite.
  fwrite(&bebida, sizeof(struct Informacion), 1, aFile);
  fwrite(&comida, sizeof(struct Informacion), 1, aFile);
  
  // Cerramos el archivo que usamos para ingresar los datos
  fclose(aFile);
  
  return 0;
}