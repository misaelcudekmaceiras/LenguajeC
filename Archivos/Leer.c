#include <stdio.h>
#include <stdlib.h>

int main(){
  // Puntero de tipo FILE (Archivo)
  // El long es para saber el ancho del archivo.
  // El puntero a char es donde se va a guardar la información del archivo.
  // El size_t se usa para saber el largo de un objeto.
  FILE *aFile;
  long aSize;
  char *c;
  
  // Abrimos el archivo en modo lectura
  aFile = fopen("informacion.txt", "r");
  
  if(aFile == NULL){
    // En caso de no existir, le devolvemos el error
    printf("El archivo no existe");
  } else {
    // Acá averiguamos el ancho del archivo.
    // El fseek posiciona al puntero al final del archivo
    // El ftell devuelve la posición (número) sobre la que se encuentra el puntero
    // El rewind vuelve el puntero hacia el principio
    fseek(aFile, 0, SEEK_END);
    aSize = ftell(aFile);
    rewind(aFile);
    
    // Asignamos al espacio de memoria la cantidad de bytes
    // que vamos a utilizar, que serían los bytes de un char
    // multiplicado por el largo del archivo (Cantidad de elementos)
    c = (char*) malloc(sizeof(char)*aSize);
    
    if(c == NULL){
      // En el caso de no poder asignar el espacio devolvemos el error
      printf("No se pudo crear el espacio de memoria");
    }else{
      // Acá cargamos toda la información del archivo dentro
      // del espacio de memoria creado
      // El fread se utiliza para lo que acabamos de decir
      // En el primer argumento se ingresa el puntero al espacio de memoria
      // En el segundo se indica el tamaño en bytes de cada elemento
      // En el tercero el largo del archivo (Cantidad de elementos)
      // En el cuarto el puntero que indica la entrada de la información
      fread(c, sizeof(char), aSize, aFile);
      
      // Mostramos todo lo que hay en el espacio de memoria
      printf("%s\n", c);
      
      // Cerramos el archivo que usamos para leer los datos
      fclose(aFile);
    }
  }
  
  /////////////////////////////////////////////////////////////
  
  // Liberamos el espacio de memoria
  free(c);
  
  return 0;
}
