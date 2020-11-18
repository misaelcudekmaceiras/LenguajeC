/* Orion Lawlor's Short UNIX Examples, olawlor@acm.org 2004/9/5
Shows how to use fork() in a UNIX program.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

void *doWork(const char *where)
{
	int i;
	int b=1,a=1;
	printf("Entered work function (%s)\n",where);
	fflush(stdout);
	for (i=0;i<100000000;i++)
		b=a+b;
	printf("Leaving work function (%s)\n",where);
	return (void *)b;
}

int main()
{
	/*Spawn a new process to run alongside us.*/
	pid_t pid=fork();
	if (pid==0) { /* child process */
		doWork("child");  
		exit(0);
	}
	else { /* pid!=0; parent process */
		doWork("parent");
		waitpid(pid,0,0); /* wait for child to exit */
	}
	return 0;
}

/*<@>
<@> ******** Program output: ********
<@> Entered work function (child)
<@> Leaving work function (child)
<@> Entered work function (parent)
<@> Leaving work function (parent)
<@> */
