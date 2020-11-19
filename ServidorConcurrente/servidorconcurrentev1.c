#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

 int contclientes=0;//variable global
 
 void manejaSIGCHLD(int e)
{
  printf("Un hijo finalizo,cliente desconectado\n");
   waitpid(-1, NULL, 0);
  contclientes--;
}
 
 
 
int main(int argc , char *argv[])
{
    int socket_desc , new_socket , c;
    struct sockaddr_in server , client;
    char *message;
    
    int pid=0;
    signal(SIGCHLD,manejaSIGCHLD);
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 80 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind failed");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 10);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    
    while(1){
            while(contclientes<5)
            {
                new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
                if (new_socket<0)
                {
                    perror("accept failed");
                    return 1;
                }
                contclientes++;
                
                printf("Atendiendo al cliente %d \n",contclientes);
                
                pid=fork();// MAL:-1; HIJO:0; PADRE: pid_hijo>0
                
                if(pid==0)
                {        //Reply to the client
                message = "<!DOCTYPE html><html><body><h1>Nuestro Server basico</h1><p>Este servidor es muy simple</p></body></html>";
                write(new_socket , message , strlen(message));
                sleep(2);
                close(new_socket); //cierra conexion con cliente
                exit(0);
                }
                else if(pid<0)
                {
                printf("Fallo fork\n");   
                exit(1);
                }

            }
            printf("Se alcanzaron la maxima cantidad de clientes que es posible atender\n");
            sleep(1);
    }
    
    printf("Se atendieron %d fin del servidor\n",contclientes);
    close(socket_desc);//libera el puerto al sist operativo
    return 0;
}
