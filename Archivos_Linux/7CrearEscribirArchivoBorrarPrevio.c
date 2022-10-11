// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <unistd.h>
#include <string.h>

struct dato
{
	int num;
	char nombre[20];
};

extern int errno;
int main()
{
	struct dato d1;
	d1.num=0xaabbccdd;
	strcpy(d1.nombre,"misa");
	
	
	int fd = open("ejemplo.bin", O_WRONLY | O_CREAT | O_TRUNC ,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH );
	//Si no existe y no se crea error
	//Si existe se borra 0_TRUNC
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
		printf("Escritos %ld \n",write(fd,&d1,sizeof(struct dato)) );//escritura sin verificar errores
		
		

		close(fd);//tambien puede fallar
	}
	return 0;
}
