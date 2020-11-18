#include <sys/shm.h>
#include <stdio.h>

void main(){

// Creo la clave que van a usar los procesos para acceder
int clave = ftok ("/home",123);

// Asigno en id_memoria la direccion respectiva a 'clave'
// Que es la misma que usamos en el otro prog, sin parametro CREAT
int id_memoria = shmget (clave, sizeof(int) * 3, 0777);

// Vinculo los datos del prog con el segmento
int *datos;
datos = shmat(id_memoria, 0, 0);

// Leo los datos que se escriben con el otro programa
// en nuestro segmento de memoria

printf ("\n** El primer numero es: %d \n", datos[0]);
printf ("** El segundo numero es: %d \n", datos[1]);
printf ("** El tercer numero es: %d \n\n", datos[2]);

}
