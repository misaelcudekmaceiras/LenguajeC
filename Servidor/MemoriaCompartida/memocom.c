#include <sys/shm.h>
#include <stdio.h>

void main(){

// Creo la clave que van a usar los procesos
// con la llamada al sistema ftok
int clave = ftok ("/home",123);

// Creo segmento de memoria compartida usando 'shmget',
// con el flag CREAT
int id_memoria = shmget (clave, sizeof(int) * 3, 0777 | IPC_CREAT);

// Vinculo los datos prog del con el segmento
int *datos;
datos = shmat(id_memoria, 0, 0);

// Escribo en el segmento compartido como un array
printf("\nIngrese primer numero: ");
scanf("%d", &datos[0]);
printf("Ingrese segundo numero: ");
scanf("%d", &datos[1]);
printf("Ingrese tercer numero: ");
scanf("%d", &datos[2]);

printf("\nEjecute el programa de lectura !\n");
printf("\nPresione ENTER para finalizar.\n");
char c;
scanf("%c", &c);
getchar();

printf("Liberando memoria compartida...\n\n");
// Desasocio el segmento de datos del proceso con el
// de memoria compartida usando 'shmdt'
shmdt ((int *)datos);

// Libero el segmento de memoria usando 'shmctl',
// con el flag RMID
shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);


}
