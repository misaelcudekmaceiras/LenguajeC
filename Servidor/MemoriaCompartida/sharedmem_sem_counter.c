/* sysV IPC shared memory - read from shared memory
   shrmem2_sysV.c
    
    meant to be used with shrmem1_sysV:
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
    #include <sys/sem.h>
    #define MEM_SZ 4096

    union semun {
      int              val;    /* Value for SETVAL */
      struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
      unsigned short  *array;  /* Array for GETALL, SETALL */
      struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
    };

    
    struct shared_use_st {
      int counter;
    };
    
    int main(int argc, char *argv[]) {
      void *shared_mem = (void *) 0;
      struct shared_use_st *shared_stuff;
      int shmid;
      int cont;
      int pid;
      int semid;
      key_t key;
      union semun arg;
      struct sembuf sb = {0, -1, 0};  /* arrancar en lock */

      
      shmid = shmget( (key_t)1234, MEM_SZ, 0600 | IPC_CREAT);
      if (shmid == -1) {
        perror("shmget in shrmem2_sysV failed");
        exit(EXIT_FAILURE);
      }

      shared_mem = shmat(shmid, (void *)0, 0);
      if (shared_mem == (void *)-1) {
        perror("shmat in shrmem2_sysV failed");
        exit(EXIT_FAILURE);
      }
      printf("memory attached at %X\n", (int)shared_mem);
      shared_stuff = (struct shared_use_st *)shared_mem;
      shared_stuff -> counter = 0;

      if ((key = ftok(argv[0], 'J')) == -1) {
         perror("ftok");
         exit(1);
      }

      if ((semid = semget(key, 1, IPC_CREAT | 0600)) == -1) {
         perror("semget");
         exit(1);
      }

        /* initialize semaphore #0 to 1: */
        arg.val = 1;
        if (semctl(semid, 0, SETVAL, arg) == -1) {
            perror("semctl");
            exit(1);
        }

      pid=fork();
      for (cont=0;cont<1000000;cont++) {
        sb.sem_op = -1; /* lock */
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(1);
        }

        shared_stuff -> counter = shared_stuff -> counter+1;
        sb.sem_op = 1; /* unlock */
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(1);
        }

      }
      if (pid == 0){
        exit(0);           /* El hijo se muere */
      }
      wait(NULL); /* Esperar a que se muera el hijo */
      printf("Contador: %d\n", shared_stuff -> counter);

      if (shmdt(shared_mem) == -1) {
        perror("shmdt in shrmem2_sysV failed");
        exit(EXIT_FAILURE);
      }
      
      if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl in shrmem2_sysV failed");
        exit(EXIT_FAILURE);
      }

        if (semctl(semid, 0, IPC_RMID, arg) == -1) {
            perror("semctl");
            exit(1);
        }
        
      exit(EXIT_SUCCESS);
    }
