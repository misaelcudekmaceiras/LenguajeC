#include <pthread.h>
#include <stdio.h>
void* char_print (void* parameters) {
  int i;
  for(i = 0; i < 300000; ++i)
    fputc('x', stderr);
  return NULL;
}
int main() {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, &char_print, NULL);
  printf("Esperando a %ld",thread_id);
  pthread_join (thread_id, NULL);//Mostrar que pasa si se comenta join
  printf("Fin del programa\n");
  return 0;
}
