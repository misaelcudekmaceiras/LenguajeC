#include <stdio.h>

struct IP
{
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    unsigned char byte4;
};

int main()
{
    struct IP mascara={255,255,255,0};
    struct IP iphost={192,168,1,134};
    struct IP nombreRed;
    struct IP ipbroadcast;
  
    nombreRed.byte1=mascara.byte1 & iphost.byte1;
    nombreRed.byte2=mascara.byte2 & iphost.byte2;  
    nombreRed.byte3=mascara.byte3 & iphost.byte3;
    nombreRed.byte4=mascara.byte4 & iphost.byte4;
    
    ipbroadcast.byte1= ~mascara.byte1 | nombreRed.byte1;
    ipbroadcast.byte2= ~mascara.byte2 | nombreRed.byte2;  
    ipbroadcast.byte3= ~mascara.byte3 | nombreRed.byte3;
    ipbroadcast.byte4= ~mascara.byte4 | nombreRed.byte4;
    
    
    
    printf("Su mascara de red es: %u.%u.%u.%u\n",mascara.byte1,mascara.byte2,mascara.byte3,mascara.byte4);
    printf("Su ip es: %u.%u.%u.%u\n",iphost.byte1,iphost.byte2,iphost.byte3,iphost.byte4);
    printf("EL nombre de su red es: %u.%u.%u.%u\n",nombreRed.byte1,nombreRed.byte2,nombreRed.byte3,nombreRed.byte4);
    printf("La dire de broadcast de su red es: %u.%u.%u.%u\n",ipbroadcast.byte1,ipbroadcast.byte2,ipbroadcast.byte3,ipbroadcast.byte4);
    
  return 0;
}

