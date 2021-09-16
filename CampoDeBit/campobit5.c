#include<stdio.h>
#include<string.h>

struct permiso
{
    unsigned char ur:1;
    unsigned char uw:1;
    unsigned char ux:1;
    
    unsigned char gr:1;
    unsigned char gw:1;
    unsigned char gx:1;
    
    unsigned char or:1;
    unsigned char ow:1;
    unsigned char ox:1;
};


int main()
{
struct permiso sopermi;

sopermi.ur=1;
sopermi.uw=1;
sopermi.ux=0;    
sopermi.gr=1;
sopermi.gw=0;
sopermi.gx=0;
sopermi.or=1;
sopermi.ow=0;
sopermi.ox=0;

printf("El tamaño ocupado es: %ld \n",sizeof(sopermi));

printf("%c",sopermi.ur ? 'r':'-' );
printf("%c",sopermi.uw ? 'w':'-' );
printf("%c",sopermi.ux ? 'x':'-' );

printf("%c",sopermi.gr ? 'r':'-' );
printf("%c",sopermi.gw ? 'w':'-' );
printf("%c",sopermi.gx ? 'x':'-' );

printf("%c",sopermi.or ? 'r':'-' );
printf("%c",sopermi.ow ? 'w':'-' );
printf("%c\n",sopermi.ox ? 'x':'-' );
    



return(0);
}

