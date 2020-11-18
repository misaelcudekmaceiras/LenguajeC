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
        struct sembuf sb = {0, -1, 0};  /* set to allocate resource */

        if ((key = ftok("semdemo.c", 'J')) == -1) {
            perror("ftok");
            exit(1);
        }

        /* grab the semaphore set created by seminit.c: */
        if ((semid = semget(key, 1, 0)) == -1) {
            perror("semget");
            exit(1);
        }

        printf("Press return to lock: ");
        getchar();
        printf("Trying to lock...\n");

        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(1);
        }

        printf("Locked.\n");
        printf("Press return to unlock: ");
        getchar();

        sb.sem_op = 1; /* free resource */
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(1);
        }

        printf("Unlocked\n");

        return 0;
    }
