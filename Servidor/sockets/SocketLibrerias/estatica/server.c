#include "sock-lib.h"

int main ()
{
	int sockfd;			/* File Descriptor del socket por el que el
					servidor "escuchará" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de
					puerto local */
	int sockdup;
	
	fd_set readfds;
	
	FD_ZERO(&readfds);
	

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}
	
	

	while(1)
	{
	  FD_SET(STDIN, &readfds);
	  FD_SET(sockfd, &readfds);
		
	  if (select(sockfd+1, &readfds, NULL, NULL, NULL) == -1) 
		{
		  perror("select");
		  exit(1);
		}
		
		
		if (FD_ISSET(STDIN, &readfds))
		  exit(0);

	  
		sockdup = Aceptar_pedidos (sockfd);
		
		if (write (sockdup, message , sizeof (message)) == -1)
		{
			perror("Error escribiendo mensaje en socket");
			exit (1);
		}
		close(sockdup);
	}
	exit(0);
}
