#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<stdlib.h>
 
 /*
  para correr sudo con prioridad nice -n -20 ./servidor
  
  */
 
//FILTRADO DE COMUNICACIONES SALIENTES AL PUERTO 8888
//sudo iptables -A OUTPUT -p tcp --dport 8888  -j DROP

 
int main(int argc , char *argv[])
{
    int socket_desc , new_socket , c,d=0;
    int veces=atoi(argv[3]);
    struct sockaddr_in server , client;
    char *message;
    unsigned long long int i=0;
    char letra='A';
    int level; int optname;
    void *optval;
    socklen_t *optlen;
    
    if(argc!=4)
    {
        puts("Uso ./server <tambytes_de_mensaje> <ip a escuchar> <N°_mensajes_a_enviar> :-( ");
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
    
    
     
    //Crea el socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("No se pudo crear socket");
        exit(1);
    }
     
    //Prepara the sockaddr_in structure
    server.sin_family = AF_INET;
    //server.sin_addr.s_addr = INADDR_ANY; para tomar de todos las interfaces
    server.sin_addr.s_addr =inet_addr(argv[2]); //solo escucha de la ip que te digo por argv
    server.sin_port = htons( 8888 ); // puerto sarasa 
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind fallo");
        exit(1);
    }
    puts("Asociacion de Puerto Lista");
     
int rcvBufferSize;
int sockOptSize = sizeof(rcvBufferSize);
getsockopt(socket_desc, SOCK_STREAM, SO_RCVBUF, &rcvBufferSize, &sockOptSize);
printf("El tamaño de el buffer de recepcion es %d\n", rcvBufferSize);   


int sndbuf;
int len2 = sizeof(sndbuf);
getsockopt(socket_desc, SOCK_STREAM, SO_SNDBUF, &sndbuf, &len2);
int mss2;
len2 = sizeof(mss2);
getsockopt(socket_desc, IPPROTO_TCP, TMP_MAX, &mss2, &len2);
printf("El tamaño de el buffer de transmision es  %d\n", sndbuf);


    
    //Listen maneja las conexiones de clientes +1 en espera
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Esperando conexiones..");
    c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (new_socket<0)
    {
        perror("Fallo");
        exit(1);
    }
     
    puts("Coneccion Establecida Aprente Enter 4 veces para iniciar la TX");
    
    getchar();
    getchar();
    getchar();
    getchar();
    printf("Comienzo de Transmicion de %d mensajes de %d bytes cada uno\n",atoi(argv[3]),atoi(argv[1])); 
    //Reply to the client

for(d=0;d<veces;d++)
{
    send(new_socket, message ,strlen(message) , 0);
    printf("Mensaje %d transmitido\n",d); 
//    printf("Transmicion pausada teclee enter 3 veces para continuar\n");
//    getchar();
//    getchar();
//    getchar();
}
printf("Fin de la transmision\n"); 
close(socket_desc);
    
     
    return 0;
}
