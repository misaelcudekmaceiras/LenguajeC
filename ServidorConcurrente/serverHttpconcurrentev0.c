#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


 void manejadorSIGCHLD(int sig);
     int i=10;//atiendo 10 clientes varaible global, se ve de todos lados
     
     
int main(int argc , char *argv[])
{
    int socket_desc , new_socket , c;
    struct sockaddr_in server , client;
    char *message;
    
        int pid;
        
        
        signal(SIGCHLD, manejadorSIGCHLD);
        
        
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
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    
    while(1){
                while(i>0)
                {//********repeticion
                    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
                    if (new_socket<0)
                    {
                        perror("accept failed");
                        return 1;
                    }
                    
                    puts("Connection accepted");
                    
                    
                    i--;
                    printf("Contador de Clientes %d\n",10-i);
                    
                    pid=fork();
                    
                    if(pid==0)
                        {//Soy hijo
                        message = "<!DOCTYPE html><html><body><h1>Servidor Web</h1><p>Este es un servidor de trucho</p></body></html>";
                        write(new_socket , message , strlen(message));
                        
                        close(new_socket);//cierro el cliente
                        exit(0);    //ojo el hijo termino , e incrementar i en 1
                        }
                    
                    //Reply to the client

                
                }
    printf("Maxima cantidad de clientes conectados simultanea valor de i: %d\n",i);            
    sleep(1);
                
    }
    //********repeticion
    close(socket_desc);
    
    return 0;
}

void manejadorSIGCHLD(int sig)
{
  while (waitpid(-1, NULL, WNOHANG) != 0);
  i++;
}
