#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
struct memoria
{
  int contador;
};
int main(int argc, char *argv[])
{
  int ctr;
  key_t key = ftok("memcompartida", 'a');
  int shmid = shmget(key, sizeof(struct memoria), IPC_CREAT|0660);
  char *addr = shmat(shmid, NULL, 0);
  struct memoria *pmem = (struct memoria *)addr;
  pmem->contador = 0;
  int rc = fork();
  if (rc == 0)
  {   // Hijo
    for (ctr=0; ctr<10000000; ctr++)
    {
      pmem->contador = pmem->contador+1;
    }
    shmdt(addr);
    exit(0);
  }
  for (ctr=0; ctr<10000000; ctr++)
  {
    pmem->contador = pmem->contador+1;
  }
  wait(NULL);
  printf("Contador = %d\n", pmem->contador);
  shmdt(addr);
  
}