#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/wait.h>

void die(char * msg);

int main(int argc, char *argv[]) {
   int sockfd;
   struct sockaddr_in their_addr;  /* IP y puerto del servidor */
   struct hostent *he;
   int numbytes, puerto;
   if (argc != 4) {
      printf("uso: 6.4.cliente hostname puerto mensaje\n");
      exit(0);
      }

   // Convertimos el hostname a su direccion IP
   if ((he=gethostbyname(argv[1])) == NULL) die("gethostbyname");

   // Creamos el socket
   if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) die("socket");

   // Cargamos la estructura
   their_addr.sin_family = AF_INET;  /* host byte order */
   puerto = atoi(argv[2]);
   their_addr.sin_port = htons(puerto);  /* network byte order */
   their_addr.sin_addr = *((struct in_addr *)he->h_addr);
   bzero(&(their_addr.sin_zero), 8);

   // Enviamos el mensaje
   if ((numbytes=sendto(sockfd, argv[3], strlen(argv[3]), 0, \
      (struct sockaddr *)&their_addr, \
      sizeof(struct sockaddr))) == -1) die ("sendto");
   printf("enviados %d bytes hacia %s\n",numbytes, inet_ntoa(their_addr.sin_addr));
   close(sockfd);
   return 0;
}

void die(char * msg) {
   char texto[80];
   sprintf(texto, "[%d] %s", getpid(), msg);
   perror(texto);
   exit(EXIT_FAILURE);
   }
