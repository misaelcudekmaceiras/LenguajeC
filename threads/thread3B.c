#include <pthread.h>
#include <stdio.h>

//ps -mo pid,tid,lwp,%cpu,cpuid,lastcpu -p <PID>
//pstree -p <PID>

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

  printf("Termine %c %d\n",cara=INFO->car,canti=INFO->cant);

  return (0);
}
int main() {
  struct infoAlThread i1={'A',300000};
  struct infoAlThread i2={'B',20000};
  struct infoAlThread i3={'C',180};
  pthread_t thread_id1;
  pthread_t thread_id2;
  pthread_t thread_id3;
  pthread_create(&thread_id1, NULL, &char_print, &i1);
  pthread_create(&thread_id2, NULL, &char_print, &i2);
  pthread_create(&thread_id3, NULL, &char_print, &i3);

  //Si no me importa cunado terminan uso detach
  pthread_detach( thread_id1 );
  pthread_detach( thread_id2 );
  pthread_detach( thread_id3 );

  getchar();
  printf("\nFin del programa \n");
  return 0;
}
