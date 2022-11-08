#include <pthread.h>
#include <stdio.h>

// gcc th.c -o threadsmisa -lpthread
//ps -LfC threadsmisa
// ps -fea | grep threadsmisa
void* print_xs (void* unused) 
{
  while(1)
    {
    fputs("X",stdout);  
    }
    
  return NULL;
}

int main () 
{
  pthread_t thread_id;
  pthread_create(&thread_id,NULL,&print_xs,NULL);
  //&thread_id se completa con ID si se ejecuta bien
  //1º NULL , si queres poner atributos para el thread
  //direcion de ejecuccion de la funcion
  //2º NULL , unico parametro a pasar al thread, si queres + de 1 , struct
  
  while(1)  //discutir
  {
    fputs("O",stdout);   
   }
   
  return(0);
}
