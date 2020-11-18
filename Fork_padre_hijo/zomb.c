
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include<time.h>

int main(void){

	pid_t p;
	int i,pnum,hnum;

	p=fork();
	if (!p) {
		
		while(pnum<999999){printf("\nproceso padre %d\n\n",pnum++);}
	}else{
		while(hnum<999999){printf("\nProceso hijo  %d\n\n",hnum++);}
		
	}
	return 0;
}

