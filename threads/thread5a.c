#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *fd;
pthread_mutex_t mutex;
void *escribe (void *data) {
  char str[30];
  strcpy(str,(char*)data);
  printf("La cadena a escribir en el archivo es:  %s",str);
  /* se lock el mutex para que nadie mas escriba en el archivo */
//  pthread_mutex_lock(&mutex);
//  printf("Mutex locked\n");
  printf("Escribo en el archivo\n");
  if (fprintf(fd,"%s",str) < 0 ) {  perror("fwrite");
    //pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
  }
  /* se unlock el mutex para que otro thread pueda usar el archivo*/
  //printf("Mutex unlocked\n");
  //pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}
int main() {
  int count,cant;
  char buf[30];
  pthread_t id;
  printf("Abro archivo al que escribiran los threads\n");
  if (((fd = fopen("archivo.txt","w+")) == NULL)) {
    perror("fopen");
    exit (1);
  }
 // printf("Inicializo el mutex\n");
  //pthread_mutex_init(&mutex,NULL);
  count=20;
  cant=1;
  while(count) {
    sprintf(buf,"Soy el thread numero %d\n",cant);
    printf("El contenido del buffer es: %s",buf);
    /*creacion del thread*/
    if (pthread_create(&id,NULL,&escribe,buf)!= 0 ) {
      perror("pthread_create");
      exit(1);
    }
    cant++;
    count--;
   // sleep(2);
  }
  pthread_join(id,NULL);
  fclose(fd);
  exit(0);
}
