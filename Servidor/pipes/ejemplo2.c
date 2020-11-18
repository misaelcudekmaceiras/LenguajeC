#include <stdlib.h>
#include <stdio.h>

void arrancarpipe();

int
main(int argc, char **argv)
{
	int pid, status;
	int fd[2];
	
	pipe(fd);
	
	switch(pid = fork()){
	  
	  case 0: /*hijo*/
	    arrancarpipe(fd);
	    exit(0);
	    
	  default: /*padre*/
	    while((pid = wait(&status)) != -1)
	      fprintf(stderr, "proceso %d salió con %d\n", pid, WEXITSTATUS(status));
	    break;
	    
	  case -1:
	    perror("fork");
	    exit(1);
	}
	exit(0);
}
char *cmd1[] = { "/bin/ls", "-al", "/", 0};
char *cmd2[] = { "/usr/bin/tr", "a-z", "A-Z", 0};

void
arrancarpipe(int pfd[])
{
    int pid;
    
    switch (pid = fork()){
      
      case 0: /*hijo*/
	dup2(pfd[0], 0);
	close(pfd[1]); /*el hijo no necesita este final del pipe*/
	execvp(cmd2[0], cmd2);
	perror(cmd2[0]);
      
      default: /*padre*/
	dup2(pfd[1], 1);
	close(pfd[0]); /*el padre no necesita este final del pipe*/
	execvp(cmd1[0], cmd1);
	perror(cmd1[0]);
	
      case -1:
	 perror("fork");
	 exit(1);
	 
    }
}