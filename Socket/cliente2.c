#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<stdlib.h>
#include<math.h>
 
int main(int argc , char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *message;
    message=(char*)malloc(1024*1024*1024);
    unsigned long long int rx=0,r=0;
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
         
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
     
    puts("Connected\n");
     
    //Send some data
    while( (r=recv(socket_desc, message , 1024*1024*1024 , 0)) > 0  )
    {
    puts("Reply received\n");
    printf("recibidos %lld \n",r);
    puts(message);  puts("\n");
    }
    
    
    
    
     
    return 0;
}
