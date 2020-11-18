#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MSGSIZE 32

char *msg1 = "hola #1";
char *msg2 = "hola #2";
char *msg3 = "hola #3";

void main(void)
{
   char inbuf[MSGSIZE];

   int p[2], j;
   pid_t pid;

   /* open pipe */

   if (pipe(p) == -1)
   {
     perror("pipe call error");
     exit(1);
   }

   switch(pid = fork())
   {
     case -1:
       perror("error: fork call");
       exit(2);

     case 0:  /* si es el hijo escribir al pipe */
       close(p[0]);  /* primero cerrar el extermo de lectura del pipe */
	 write(p[1], msg1, MSGSIZE);
	 write(p[1], msg2, MSGSIZE);
	 write(p[1], msg3, MSGSIZE);
       break;

     default:   /* el padre lee el pipe */
       close(p[1]);  /* primero cerrar el extremo de escritura del pipe */
  	 for(j=0; j<3; j++)
	 {
         read(p[0], inbuf, MSGSIZE);
	   printf("Parent: %s\n", inbuf);
	 }
       wait(NULL);
   }
   exit(0);
}

