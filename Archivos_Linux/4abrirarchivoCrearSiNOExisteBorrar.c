
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
 #include <unistd.h>

extern int errno;
int main()
{	
	
	int fd = open("ejemplo.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH );
	//Si no existe y no se crea error
	//touch ejemplo.txt
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
		close(fd);//tambien puede fallar
	}
	return 0;
}
