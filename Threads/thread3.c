#include <pthread.h>
#include <stdio.h>

struct infoAlThread
{
    char car;
    int cant;
};

void* char_print (void* param) {
  int i;
  struct infoAlThread * INFO =(struct infoAlThread *)param;
  int canti=INFO->cant;
  char cara=INFO->car;
  for(i = 0; i < canti; ++i)
    fputc(cara, stderr);
  return (0);
}
int main() {
  struct infoAlThread i1={'A',300};
  struct infoAlThread i2={'B',200};
  struct infoAlThread i3={'C',18};
  pthread_t thread_id1;
  pthread_t thread_id2;
  pthread_t thread_id3;
  pthread_create(&thread_id1, NULL, &char_print, &i1);
  pthread_create(&thread_id2, NULL, &char_print, &i2);
  pthread_create(&thread_id3, NULL, &char_print, &i3);
  //printf("Esperando a %ld",thread_id);
  pthread_join (thread_id1, NULL);
  pthread_join (thread_id2, NULL);
  pthread_join (thread_id3, NULL);
  printf("\nFin del programa \n");
  return 0;
}
