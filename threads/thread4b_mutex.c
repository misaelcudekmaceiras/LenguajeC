#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//******OJO CON ESTO*********
pthread_mutex_t my_mutex;
//******OJO CON ESTO*********

void* masmas (void* param)
{
  int * p=(int*)param;
  for(;;)
  {
  //pongo candado
  pthread_mutex_lock(&my_mutex);

  if(*p <10)
  {
  (*p)++;
  }

  printf("%d\n",*p);//no haria falta que este dentro

  pthread_mutex_unlock(&my_mutex);
  //saco candado

  }

  return (0);
}

void* menosmenos (void* param)
{
  int * p=(int*)param;
  for(;;)
  {
  //pongo candado
  pthread_mutex_lock(&my_mutex);
  if(*p >0)
  {
  (*p)--;
  }
  printf("%d\n",*p);//no haria falta que este dentro

  pthread_mutex_unlock(&my_mutex);
  //saco candado
  }
  return (0);
}


//sinchada entre threads

int main()
{
  int valor=0;

  pthread_t thread_id1;
  pthread_t thread_id2;

  if (pthread_mutex_init(&my_mutex,NULL))   //si hay init si o si hay destroy
  {
    printf("No pude inicializar el mutex\n");
    exit(1);
  }

  pthread_create(&thread_id1, NULL, &masmas, &valor);
  pthread_create(&thread_id2, NULL, &menosmenos, &valor);

  //printf("Esperando a %ld",thread_id);
  pthread_join (thread_id1, NULL);
  pthread_join (thread_id2, NULL);


  pthread_mutex_destroy(&my_mutex);//destruir si no usas mas o antes de ir. si es mutex en stack no es obligatorio pero recomendable para futuro.


  printf("\nFin del programa \n");
  return 0;
}
