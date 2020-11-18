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
  while(1)  //discutir
  {
    fputs("O",stdout);   
   }
   
  return(0);
}
