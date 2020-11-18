#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

#define MYPORT 3456    // Numero de puerto donde se conectaran los clientes
#define BACKLOG 2      // Tamaño de la cola de conexiones recibidas

int sockfd; // El servidor escuchara por sockfd
int newfd;  // las transferencias de datos se realizar mediante newfd

void sigint_hand(int my_signal);
void sigchld_hand(int my_signal);
void die(char * msg);
int child(void);

int main(void) {
   pid_t proceso;
   struct sockaddr_in my_addr;	// contendra la IP y el numero de puerto local
   struct sockaddr_in their_addr;// Contendra la IP y numero de puerto del cliente
   int sin_size;	               // Contendra el tamaño de la escructura sockaddr_in

   signal(SIGINT,sigint_hand);
   signal(SIGCHLD,sigchld_hand);

   proceso=getpid();

   // Crea un socket y verifica si hubo algun error
   if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      perror("socket");
      exit(1);
      }

   /* Asignamos valores a la estructura my_addr para luego 
   poder llamar a la funcion bind() */
   my_addr.sin_family = AF_INET;
   // debe convertirse a network byte order porque es enviado por la red
   my_addr.sin_port = htons(MYPORT); 
   // automaticamente usa la IP local
   my_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
   // rellena con ceros el resto de la estructura
   bzero(&(my_addr.sin_zero), 8);
   if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
      perror("bind");
      exit(1);
      }

   // Habilitamos el socket para recibir conexiones
   if (listen(sockfd, BACKLOG) == -1) {
      perror("listen");
      exit(1);
      }

   printf("[%d] Server escuchando en: %s puerto %d\n", proceso, inet_ntoa(my_addr.sin_addr), MYPORT);
   sin_size = sizeof(struct sockaddr_in);

   while(1) {
      /*Se espera por conexiones ,*/
      printf("[%d] Entró en el accept\n", proceso);
      newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
      printf("[%d] Salió del accept\n", proceso);
      if (newfd == -1) die("accept");
      printf("[%d] Conexion desde: %s\n", proceso, inet_ntoa(their_addr.sin_addr));
      if (fork()) {
         close(newfd);
         }
      else {
         close(sockfd);
         child();
         close(newfd);
         return 0;
         }
      }
   close(sockfd);
   return 0;
}

void sigint_hand(int my_signal) {
   printf("[%d] Finalizando ...\n", getpid());
   close(newfd);
   close(sockfd);
   exit(1);
   }

void sigchld_hand(int my_signal) {
   printf("[%d] Proceso hijo finalizado, %d\n", getpid(), wait(NULL));
   return;
   }

void die(char * msg) {
   char texto[80];
   sprintf(texto, "[%d] %s", getpid(), msg);
   perror(texto);
   exit(EXIT_FAILURE);
   }

int child(void) {
   pid_t proceso = getpid();
   char buff[200];
   int sockudpfd, port_udp, nbytes;
   struct sockaddr_in mi_dir_udp;  /* IP y numero de puerto local */
   struct sockaddr_in su_dir_udp;  /* IP y numero de puerto del cliente */
   int addr_len, numbytes;
   fd_set fdsetall, fdset;
   int maxfd;

   printf("[%d] Child iniciado\n", proceso);

   // Creo el socket UDP
   if ((sockudpfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) die("socket");
   mi_dir_udp.sin_family = AF_INET;     /* host byte order */
   mi_dir_udp.sin_addr.s_addr = INADDR_ANY;  /* asigna automaticamente la IP local */
   bzero(&(mi_dir_udp.sin_zero), 8);  /* rellena con ceros el resto de la estructura */
   addr_len = sizeof(struct sockaddr);

   //Envio saludo por TCP al cliente
   sprintf(buff, "[%d] Conexión Aceptada\n", proceso);
   if (send(newfd, buff, strlen(buff), 0) == -1) die("send");

   // Busco un puerto UDP libre
   for(port_udp = 10000; port_udp < 11000; port_udp++) {
      mi_dir_udp.sin_port = htons(port_udp); /* network byte order */
      if (bind(sockudpfd, (struct sockaddr *)&mi_dir_udp, sizeof(struct sockaddr))  != -1) {
         break;
         }
      }
   // Envio del port abierto por TCP
   sprintf(buff, "Esperando mensajes por UDP puerto %d\n", port_udp);
   if (send(newfd, buff, strlen(buff), 0) == -1) die("send");

   FD_ZERO(&fdsetall);
   FD_SET(newfd, &fdsetall);
   FD_SET(sockudpfd, &fdsetall);
   if (newfd > sockudpfd) maxfd = newfd+1;
   else maxfd = sockudpfd+1;
   printf("[%d] maxfd: %d ( %d %d )\n", proceso, maxfd, newfd, sockudpfd);
   while (1) {
      fdset=fdsetall;
      printf("[%d] Entró en el select\n", proceso);
      if (select(maxfd, &fdset, NULL, NULL, NULL) == -1) die("Select");
      printf("[%d] Salió del select\n", proceso);
      if (FD_ISSET(newfd, &fdset)) {
         // Detecto "FIN" en TCP
         buff[0]='\0';
         if ((nbytes = recv(newfd, buff, sizeof(buff),0)) == -1) die("recv");
         buff[nbytes] = '\0';
         printf("[%d] Recibí por TCP %s", proceso, buff);
         if (strncmp("FIN\n", buff,3) == 0) {
            printf("[%d] Detecto fin por TCP\n", proceso);
            break;
            }
         }
      if (FD_ISSET(sockudpfd, &fdset)) {
         // Recibí por UDP
         buff[0]='\0';
         if ((nbytes = recvfrom(sockudpfd, buff, sizeof(buff), 0 , \
            (struct sockaddr *)&su_dir_udp, &addr_len )) == -1) die("recvfrom");
         buff[nbytes] = '\0';
         printf("[%d] Recibí por UDP %d bytes, \"%s\"\n", proceso, nbytes, buff);
         }
      }
   // Cierro puerto UDP
   close(sockudpfd);
   printf("[%d] Child finalizado\n", proceso);
   return 0;
}
