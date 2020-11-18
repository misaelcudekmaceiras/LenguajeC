#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main(){
  // Puntero de tipo FILE (Archivo)
  FILE *aFile;
  unsigned int seed;
  // Creamos el archivo o lo leemos de estar creado con fopen
  // En el primer parámetro se ingresa el nombre del archivo
  // y en el segundo especifica el tipo de fichero que se
  // abrirá o se creará:
  // "r": Abre archivo para lectura (El archivo debe existir).
  // "w": Abre archivo para escritura, de no existir se crea o se sobreescribe si existe.
  // "a": Abre archivo para escritura al final del contenido, si no existe se crea.
  // "rt": Abre archivo para lectura y escritura, el fichero debe existir.
  // "wt": Crea un archivo para lectura y escritura si no existe es creado sino se sobreescribe.
  // "r+b" o "rb+": Abre un archivo binario para actualización (escritura y lectura).
  // "wb": Abre un archivo en modo binario para escritura.
  // "rb": Abre un archivo en modo binario para lectura.
  aFile = fopen("informacion.txt", "w+");
  
  // Creamos el texto que le vamos a ingresar al archivo
  char texto[] = "CHAU";
  int r=0;
  // Lo escribimos dentro del archivo con fwrite.
  // En el primer parámetro se ingresa el texto que se creó.
  // En el segundo la longitud de bytes de cada uno de los elementos a guardar.
  // En el tercero la cantidad de elementos.
  // En el cuarto el puntero hacia el archivo
  fwrite(texto, sizeof(char), sizeof(texto), aFile);
  seed=atoi("123");
    srand(getpid()*time(NULL));
    r =  rand()%10;

    printf("%d\n", r);

  sleep((int)r);
  // Cerramos el archivo que usamos para ingresar los datos
  fclose(aFile);
  
  return 0;
}
