/* sysV IPC shared memory - write to shared memory
   shrmem1_sysV.c
    
    meant to be used with shrmem2_sysV:
      start shrmem2_sysV in background,
      then start shrmem1_sysV
    */
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>
    #define MEM_SZ 4096
    
    struct shared_use_st {
      int writ_by_you;
      char some_text[BUFSIZ];
    };

    int main() {
      int run = 1;
      void *shared_mem = (void *) 0;
      struct shared_use_st *shared_stuff;
      char buffer[BUFSIZ];
      int shmid;
    
      shmid = shmget( (key_t)1234, MEM_SZ, 0666 | IPC_CREAT);
      if (shmid == -1) {
        perror("shmget in shrmem1_sysV failed");
        exit(EXIT_FAILURE);
      }
      
      shared_mem = shmat(shmid, (void *)0, 0);
      if (shared_mem == (void *)-1) {
        perror("shmat in shrmem1_sysV failed");
        exit(EXIT_FAILURE);
      }
      printf("memory attached at %p\n", shared_mem);
      shared_stuff = (struct shared_use_st *)shared_mem;
      
      while (run) {
        while (shared_stuff->writ_by_you == 1) {
          sleep(3);
          printf("Waiting for client ...\n");
        }
        printf("Enter some text: ");
        fgets(buffer, BUFSIZ, stdin);
        
        strcpy(shared_stuff->some_text, buffer);
        shared_stuff->writ_by_you = 1;
        
        if (strncmp(buffer, "end", 3) == 0) {
          run = 0;
        }
      }
      if (shmdt(shared_mem) == -1) {
        perror("shmdt in shrmem1_sysV failed");
        exit(EXIT_FAILURE);
      }
      
      exit(EXIT_SUCCESS);
    }
