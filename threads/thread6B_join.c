#include <pthread.h>// threads
#include <stdio.h>
#include <ctype.h>//  toupper((char*)param);
#include <string.h>
#include <stdlib.h>
//Se divide el procesamiento de pasar a mayusculas cada uno de los argv
//gcc -o eje procesarargu.c -lpthread
//usar: ./eje aa bbb ccCcc DDDD eeeeeeee


void* imprimir (void* param)
  {
    char * par=(char*)param;
    char * duplimalloc=strdup(par);
    //strdup de string.h duplica un string en un espacio malloqueado. Los datos generados en threads NO DEBEN estar en stack
  for(int i=0;duplimalloc[i]!='\0';i++)
  {
    if(duplimalloc[i]>='a' && duplimalloc[i]<='z')
    {
    duplimalloc[i]=duplimalloc[i]-('a'-'A');//convierte a mayus
    }
  }
  printf("%s\n",duplimalloc);

  pthread_exit(duplimalloc);//retorno el espacio malloqueado duplicado y procesado
  }

int main(int argc,char *argv[])
{
  pthread_t thread_arr[10];
  void *vretornado[10];//espacio para 10 punteros retornados


  for(int i=0;i<argc;i++)
  {
  pthread_create(&(thread_arr[i]), NULL, &imprimir, argv[i]);
  }


  for(int i=0;i<argc;i++)
  {
  pthread_join (thread_arr[i], &vretornado[i]);//Joineo a todos juntado su valor retornado
  }



  for(int i=0;i<argc;i++)
  {
  printf("Los argumentos procesados son %s :> %s\n",argv[i],(char*)vretornado[i]);
  }

  for(int i=0;i<argc;i++)
  {
    free(vretornado[i]);
  }


  printf("\nFin del programa \n");
  return 0;
}
