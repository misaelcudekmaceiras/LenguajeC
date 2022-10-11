#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <unistd.h>
#include <string.h>



extern int errno;
int main()
{

	char c='_';
	int fd = open("ejemplo.txt", O_RDONLY );
	int leido=0;
	
	
	printf("fd = %d\n", fd);
	
	if (fd ==-1)
	{
		// print which type of error have in a code
		printf("Error Number %d \n", errno);
		
		// print program detail "Success or failure"
		perror("Program");				
	}
	else
	{
		do
		{
			leido=read(fd,&c,sizeof(char));
			printf("%c ",c);
			
		}while(leido!=0);
		printf("\n");
		

		close(fd);//tambien puede fallar
	}
	return 0;
}
