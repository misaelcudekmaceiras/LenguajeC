#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>



#define PORT 3490	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */
#define STDIN 0

int	conectar (int, char **);

int	Open_conection (struct sockaddr_in *); /* Función que crea la conexión*/

int	Aceptar_pedidos (int);	/* Función que acepta una conexión entrante*/
