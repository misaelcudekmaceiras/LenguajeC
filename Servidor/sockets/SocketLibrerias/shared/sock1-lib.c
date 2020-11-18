#include "sock-lib.h"


int conectar (int argc, char * argv[])
{

	int	sockfd;
	struct hostent *he;	/* Se utiliza para convertir el nombre del host a su
				dirección IP */
	struct sockaddr_in their_addr;  /* dirección del server donde se conectará */

	/* Convertimos el nombre del host a su dirección IP */
	if ((he = gethostbyname ((const char *) argv[1])) == NULL)
	{
		herror("Error en gethostbyname");
		exit(1);
	}
 
/* Creamos el socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creación de socket");
		exit(1);
	}

/* Establecemos their_addr con la direccion del server */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = (argc == 2)? htons(PORT):htons(atoi(argv[2]));
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

/* Intentamos conectarnos con el servidor */
	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Error tratando de conectar al server");
		exit(1);
	}
	return sockfd;
}

