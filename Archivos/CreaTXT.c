#include <stdio.h>
#include <string.h>

int main(){
  // Puntero de tipo FILE (Archivo)
  FILE *aFile;

  aFile = fopen("informacion2.txt", "w");
  
    char texto[]="Este texto se va a escribir en el archivo 123\n";

  // Lo escribimos dentro del archivo con fwrite.
  // En el primer parámetro se ingresa el texto que se creó.
  // En el segundo la longitud de bytes de cada uno de los elementos a guardar.
  // En el tercero la cantidad de elementos.
  // En el cuarto el puntero hacia el archivo
  fwrite(texto, sizeof(char), strlen(texto), aFile);
  

  fclose(aFile);
  
  return 0;
}
