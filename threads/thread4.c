#include <pthread.h>
#include <stdio.h>



void* masmas (void* param)
{
  int * p=(int*)param;
  for(;;)
  {
  if(*p <10)
  {
  (*p)++;
  }
  printf("%d\n",*p);
  }

  return (0);
}

void* menosmenos (void* param)
{
  int * p=(int*)param;
  for(;;)
  {
  if(*p >0)
  {
  (*p)--;
  }
  printf("%d\n",*p);
  }
  return (0);
}


int main() {
int valor=0;

  pthread_t thread_id1;
  pthread_t thread_id2;

  pthread_create(&thread_id1, NULL, &masmas, &valor);
  pthread_create(&thread_id2, NULL, &menosmenos, &valor);

  //printf("Esperando a %ld",thread_id);
  pthread_join (thread_id1, NULL);
  pthread_join (thread_id2, NULL);

  printf("\nFin del programa \n");
  return 0;
}
