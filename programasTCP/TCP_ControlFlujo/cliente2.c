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
     
    if(argc!=2)
    {
        printf("Para ejecutar escriba ./programa <IP del server>\n");
        exit(1);
    }
    
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("No se pudo crear socket");
        exit(1);
    }
         
    server.sin_addr.s_addr = inet_addr(argv[1]); //IP del server viene de argv[1]
    server.sin_family = AF_INET; 
    server.sin_port = htons( 8888 );

       int rcvBufferSize;
int sockOptSize = sizeof(rcvBufferSize);
getsockopt(socket_desc, SOL_SOCKET, SO_RCVBUF, &rcvBufferSize, &sockOptSize);
printf("El tamaño de el buffer de recepcion es %d\n", rcvBufferSize);   

int sndbuf;
int len2 = sizeof(sndbuf);
getsockopt(socket_desc, SOCK_STREAM, SO_SNDBUF, &sndbuf, &len2);
int mss2;
len2 = sizeof(mss2);
getsockopt(socket_desc, IPPROTO_TCP, TMP_MAX, &mss2, &len2);
printf("El tamaño de el buffer de transmision es  %d\n", sndbuf);

/*
printf("Indique el tamaño del buffer de recepcion que desea usar(min 256)\n");
scanf("%d",&sndbuf);
if(-1==setsockopt(socket_desc, SOCK_STREAM, SO_SNDBUF, &sndbuf, len2))
{
printf("Ocurrio un error seteando el buffer de tx\n");    
} 
//Comentado porque me ignora el tamaño de buffer dado, tambien lo ignora si ejecuto como root o sudo
 */

    
    //Me conecto al servidor
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("Error");
        exit(1);
    }
     
    puts("Conectado con el servidor\n");
    

    
printf("Esperando Recepcion de Datos\n");         
    while( (r=recv(socket_desc, message , 1024*1024*1024 , 0)) > 0  )
    {
    printf("recibidos %lld \n",r);
    puts(message);  puts("\n");
    }
    
    
    
    
     
    return 0;
}
