#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

void main(){

	key_t Clave;
	int Id_Memoria;
	int *Memoria = NULL;
	int i,j;
	
	Clave = ftok ("/home/dv/Documentos/tp/archivo.o",33);
	
	Id_Memoria = shmget (Clave, 1024, 0777);
	
	Memoria = (int *)shmat (Id_Memoria, (char*)0, 0);
	
		for (i=0; i<10; i++){
			printf("%d",Memoria[0]);
			printf("\n");
	    		sleep(1);
  		}
}
