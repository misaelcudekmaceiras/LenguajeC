#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include <stdio_ext.h>
#include <stdlib.h>
#include <pthread.h>

#define maxClientes 5

//******OJO CON ESTO*********
pthread_mutex_t my_mutex;
pthread_mutex_t my_mutexC;
//******OJO CON ESTO*********
int globCuentath=0;


struct clienteConectado
{
    int new_socket;
    char * mensajeTX;
};

void * atiendeCliente(void * c)
{
    int clienteX_new_socket=0;
    char * mensajeTX=NULL;
     char ETX=0x4;

    //Copia de valores de estructura de cliente protec x my_mutexC
    pthread_mutex_lock(&my_mutexC);

    struct clienteConectado * pcliente=(struct clienteConectado *)c;
    clienteX_new_socket = pcliente->new_socket;
    //ojo mutex si actualizo sitio al momento escribir
    mensajeTX = pcliente->mensajeTX;

    pthread_mutex_unlock(&my_mutexC);
    //Copia de valores de estructura de cliente protec x my_mutexC

    write(clienteX_new_socket , mensajeTX , strlen(mensajeTX));
    write(clienteX_new_socket , &ETX , 1);
    sleep(2);
    close(clienteX_new_socket);

    pthread_mutex_lock(&my_mutex);
    globCuentath--;
    pthread_mutex_unlock(&my_mutex);
}


int main(int argc , char *argv[])
{
    int socket_desc , new_socket , c;
    struct sockaddr_in server , client;
    struct clienteConectado cconectado;
    char message[] = "HTTP/1.0 200 OK\n\n<!DOCTYPE html><html><body><h1>Nuestro Server basico</h1><p>Este servidor es muy simple</p></body></html>";



    //_Thread
    pthread_t  thread_ID;


        if (pthread_mutex_init(&my_mutex,NULL))   //si hay init si o si hay destroy
        {
            printf("No pude inicializar el mutex\n");
            exit(1);
        }
        if (pthread_mutex_init(&my_mutexC,NULL))   //si hay init si o si hay destroy
        {
            printf("No pude inicializar el mutex\n");
            exit(1);
        }

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("No se puedo crear el socket");
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );


    //Ojo esto arranca el puerto
    int yes=1;
    if (setsockopt(socket_desc,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1)
    {
    perror("setsockopt");
    exit(1);
    }



    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind fallo");
        return (1);
    }
    puts("bind OK");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Espero a que un cliente se me conecte en el accept");
    c = sizeof(struct sockaddr_in);

while(1)
{
    while(globCuentath<maxClientes)
    {
        new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
        if (new_socket<0)
        {
            perror("accept failed");
            return 1;
        }else
        {
        puts("Cliente conectado");
        printf("IP cliente: %s\t Puerto cliente:%d\n",inet_ntoa(client.sin_addr),client.sin_port);
        //creo un thread para que lo atienda
        pthread_mutex_lock(&my_mutex);
        globCuentath++;
        printf("Actualmente hay %d clientes\n",globCuentath);
        pthread_mutex_unlock(&my_mutex);

        pthread_mutex_lock(&my_mutexC);

        cconectado.new_socket=new_socket;//flujos IN, OUT
        cconectado.mensajeTX=message;//si el sitio no cambia
        //hace falta mutex para el array

        pthread_create(&(thread_ID), NULL, &atiendeCliente, &cconectado);
        pthread_detach( thread_ID );

        pthread_mutex_unlock(&my_mutexC);

        }
    }
    printf("Maxima cantidad de clientes conectados\n ");
    sleep(1);
}


    close(socket_desc);


    return 0;
}
