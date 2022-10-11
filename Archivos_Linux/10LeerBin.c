#include<stdio.h>
#include<stdlib.h>
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
	struct dato data;
	struct dato * pBuff=NULL;
	long int tama=0;//Puede ser -1 si es error
	int fd = open("ejemplo.bin", O_RDONLY );
	int leido=0;
	int cantEstru=0;
	
	
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
	pBuff=(struct dato *)malloc(tama);//No agrego 1 no son strines , puede fallar...
	
	lseek(fd,0,SEEK_SET);//pongo al inicio
	leido=read(fd,pBuff,tama);
	
	if(leido==tama)
	{
		//Imprimir estructuras
		//Cuantas son
		cantEstru=tama/sizeof(struct dato);
		printf("Se van a leer %d estructuras \n",cantEstru);
		for(int i=0;i<cantEstru;i++)
		{
		printf("num: %x\n",(pBuff+i)->num);
		printf("nombre: %s\n",(pBuff+i)->nombre);
		}
		
	}
	
	free(pBuff);
		
	}
	
	close(fd);//tambien puede fallar
	}
	return 0;
}
