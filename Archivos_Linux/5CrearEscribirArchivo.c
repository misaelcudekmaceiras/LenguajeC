// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <unistd.h>
#include <string.h>

extern int errno;
int main()
{	
	char cadena1[]="Este es un archivo, esta es la 1° linea\n";
	char cadena2[]="Este es un archivo, esta es la 2° linea ABCDEF\n";
	
	int fd = open("ejemplo.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH );
	//Si no existe y no se crea error
	//Si existe se escribe desde el principio
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
		write(fd,cadena1,strlen(cadena1));//escritura sin verificar errores
		
		
		if(write(fd,cadena2,strlen(cadena2)) != strlen(cadena2))
		{
		printf("Error AL escribir\n"); // causar error con :  chmod u-w
		printf("Error Number %d \n", errno);	
		}
		close(fd);//tambien puede fallar
	}
	return 0;
}
