#include <pthread.h>// threads
#include <stdio.h>
#include <ctype.h>//  toupper((char*)param);
#include <string.h>
#include <stdlib.h>
//Se divide el procesamiento de pasar a mayusculas cada uno de los argv
//gcc -o eje procesarargu.c -lpthread
//usar: ./eje aa bbb ccCcc DDDD eeeeeeee

//******OJO CON ESTO*********
pthread_mutex_t my_mutex;
//******OJO CON ESTO*********
int globCuentath=0;


void* imprimir (void* param)
  {
    char * par=(char*)param;

    //strdup de string.h duplica un string en un espacio malloqueado. Los datos generados en threads NO DEBEN estar en stack
  for(int i=0;par[i]!='\0';i++)
  {
    if(par[i]>='a' && par[i]<='z')
    {
    par[i]=par[i]-('a'-'A');//convierte a mayus
    }
  }

  printf("%s\n",par);

  //Cada thread que termine la incrementa, si termino igual nm de thread que argc , entonces esta todo listo
    pthread_mutex_lock(&my_mutex);
    globCuentath++;
    pthread_mutex_unlock(&my_mutex);

  pthread_exit(NULL);
  }

int main(int argc,char *argv[])
{
  pthread_t thread_arr[10];


    if (pthread_mutex_init(&my_mutex,NULL))   //si hay init si o si hay destroy
  {
    printf("No pude inicializar el mutex\n");
    exit(1);
  }


  for(int i=0;i<argc;i++)
  {
  pthread_create(&(thread_arr[i]), NULL, &imprimir, argv[i]);
  }


  for(int i=0;i<argc;i++)
  {
    pthread_detach( thread_arr[i] );//podria crearlos detach usando el 2 argumento del create()
  }


  do
  {
  printf("Procesando Aguarde ");
  sleep(1);
  }
  while(globCuentath!=argc);
  //Esta filosofia no hace join sino que de otra forma se da cuenta cuando finaliza el procesamiento y lo reune.

  for(int i=0;i<argc;i++)
  {
  printf("Los argumentos procesados son %s\n",argv[i]);
  }



  pthread_mutex_destroy(&my_mutex);//destruir si no usas mas o antes de ir. si es mutex en stack no es obligatorio pero recomendable para futuro.
  printf("\nFin del programa \n");
  return 0;
}
