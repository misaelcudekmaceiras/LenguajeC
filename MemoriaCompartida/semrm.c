/*
    struct sembuf
    {
      unsigned short sem_num;
      short sem_op;
      short sem_flg;
    };
*/

    union semun {
      int              val;    /* Value for SETVAL */
      struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
      unsigned short  *array;  /* Array for GETALL, SETALL */
      struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
    };

    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/sem.h>

    int main(void)
    {
        key_t key;
        int semid;
        union semun arg;

        if ((key = ftok("semdemo.c", 'J')) == -1) {
            perror("ftok");
            exit(1);
        }

        /* grab the semaphore set created by seminit.c: */
        if ((semid = semget(key, 1, 0)) == -1) {
            perror("semget");
            exit(1);
        }

        /* remove it: */
        if (semctl(semid, 0, IPC_RMID, arg) == -1) {
            perror("semctl");
            exit(1);
        }

        return 0;
    }
