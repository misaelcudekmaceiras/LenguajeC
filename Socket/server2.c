#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<stdlib.h>
 
 /*
  para correr sudo nice -n -20 ./servidor
  
  */
 
//FILTRADO DE COMUNICACIONES SALIENTES AL PUERTO 8888
//sudo iptables -A OUTPUT -p tcp --dport 8888  -j DROP

 
int main(int argc , char *argv[])
{
    int socket_desc , new_socket , c,d=0;
    struct sockaddr_in server , client;
    char *message;
    unsigned long long int i=0;
    char letra='A';
    int level; int optname;
    void *optval;
    socklen_t *optlen;
    
    if(argc!=2)
    {
        puts("Invalida cantidad de argumentos indique tamaño del mensaje a enviar :-( ");
        exit(1);
    }
    
    message=(char*)malloc(atoi(argv[1]));
    
    for(i=0;i<(atoi(argv[1])-1);i++)
    {
        *(message+i)=letra;
        if(letra>'Z')
        {
            letra='A';
        }
        else
        {
            letra++;
        }
    }
    *(message+i)='\n';
    
    
    printf("size_t %ld\n",sizeof(size_t));
    
    
     
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
     
int rcvBufferSize;
int sockOptSize = sizeof(rcvBufferSize);
getsockopt(socket_desc, SOL_SOCKET, SO_RCVBUF, &rcvBufferSize, &sockOptSize);
printf("initial socket receive buf %d\n", rcvBufferSize);   

int sndbuf;
int len2 = sizeof(sndbuf);
getsockopt(socket_desc, SOL_SOCKET, SO_SNDBUF, &sndbuf, &len2);
int mss2;
len2 = sizeof(mss2);
getsockopt(socket_desc, IPPROTO_TCP, TMP_MAX, &mss2, &len2);
printf("defaults: SO_SNDBUF = %d, MSS = %d\n", sndbuf, mss2);


    
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
     
    puts("Coneccion Establecida");
    
    getchar();
    getchar();
    getchar();
    getchar();
    puts("Comienzo de Transmicion"); 
    //Reply to the client

for(d=0;d<100;d++)
{
    send(new_socket, message ,strlen(message) , 0);
//    printf("Transmicion pausada teclee enter 3 veces para continuar\n");
//     getchar();
//     getchar();
//     getchar();
}
    
     
    return 0;
}
