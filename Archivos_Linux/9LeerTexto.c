#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include <unistd.h>
#include <string.h>



extern int errno;
int main()
{

	char * pBuff=NULL;
	long int tama=0;//Puede ser -1 si es error
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
	
	tama=lseek(fd,0,SEEK_END);//pongo al final
	
	printf("El tam del archivo es %ld\n",tama);
	if(tama>0)
	{
	pBuff=(char*)malloc(tama+1);
	
	lseek(fd,0,SEEK_SET);//pongo al inicio
	leido=read(fd,pBuff,tama);
	
	if(leido==tama)
	{
		*(pBuff+tama)='\0';
		printf("El archivo es:\n%s \n",pBuff);
	}
	
	free(pBuff);
		
	}
	
	close(fd);//tambien puede fallar
	}
	return 0;
}
