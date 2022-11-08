#include <pthread.h>// threads
#include <stdio.h>
#include <ctype.h>//  toupper((char*)param);

//gcc -o eje procesarargu.c -lpthread
//usar: ./eje aa bbb ccCcc DDDD eeeeeeee

void* imprimir (void* param)
  {
    char * par=(char*)param;
  for(int i=0;par[i]!='\0';i++)
  {
    if(par[i]>='a' && par[i]<='z')
    {
    par[i]=par[i]-('a'-'A');//convierte a mayus
    }
  }
  printf("%s\n",(char*)par);
  pthread_exit(NULL);
  }

int main(int argc,char *argv[])
{
  pthread_t thread_arr[10];

  for(int i=0;i<argc;i++)
  {
  pthread_create(&(thread_arr[i]), NULL, &imprimir, argv[i]);
  }


    for(int i=0;i<argc;i++)
  {
  pthread_join (thread_arr[i], NULL);//Joineo a todos para garantizar que temrminaron antes de seguir.
  }

  printf("\nFin del programa \n");
  return 0;
}
