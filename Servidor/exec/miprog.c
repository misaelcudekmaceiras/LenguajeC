#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[]) {
        pid_t pid = fork();
        int status;
       
        if (pid == 0) {
                // Proceso hijo
                execv("programa", argv);  // programa en bash + argumentos
                exit(127); // si algo sale mal, mostramos un error
        } else {
                // Esperamos a que termine el proceso
                waitpid(pid, &status, 0);
                // Ejecutamos el resto del codigo sobre el proceso padre
                if (status == 0) {
                        printf("mundo\n");
                }
        }
       
        return 0;
}
