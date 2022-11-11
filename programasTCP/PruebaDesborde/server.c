#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<stdlib.h>
 
 /*
  para correr sudo nice -n -20 ./servidor
  
  */
 
 
int main(int argc , char *argv[])
{
    int socket_desc , new_socket , c,d=0;
    struct sockaddr_in server , client;
    char *message=malloc(1024*1024*1024);
    printf("size_t %ld\n",sizeof(size_t));
    unsigned long long int i=0;
    while(i<1024*1024*1024)
    {
      *(message+i)=(char)('A');
      i++;
    }
    printf("fin\n");
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
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
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (new_socket<0)
    {
        perror("accept failed");
        return 1;
    }
     
    puts("Connection accepted");
     
    //Reply to the client

for(d=0;d<5;d++)
{
    send(new_socket, message ,strlen(message) , 0);
}
    
     
    return 0;
}
