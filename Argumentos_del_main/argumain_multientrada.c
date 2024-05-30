/*
//Muestra todo lo ingresado por linea de comandos
//Info1 Mariano Gonzalez _ Misael Cudek
*/

//./eje   juan pedro pablo			cada palabra un argumento distinto
//./eje   "juan pedro pablo"		todo en un solo argumento
//./eje   `cat argumain_bak.c`      cada linea un argumento distinto
//./eje   "`cat argumain_bak.c`"    todo en un solo argumento


#include<stdio.h>

int main(int argc,char * arvg[])
{
	int i=0;  
	int j=0;
	printf("La cantidad de argumentos recibidos por linea de comandos es %d \n\n",argc);
	printf("Los argumentos son\n\n");


	for(i=0;i<argc;i++)
	{
		printf("El argumento %d es %s\n\n",i,arvg[i]);
	}
  

	
	
					
					
  return (0);
}
