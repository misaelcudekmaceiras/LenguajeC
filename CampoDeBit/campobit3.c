#include<stdio.h>
#include<string.h>

struct permiso
{
    unsigned int ur:1;
    unsigned int uw:1;
    unsigned int ux:1;
    
    unsigned int gr:1;
    unsigned int gw:1;
    unsigned int gx:1;
    
    unsigned int or:1;
    unsigned int ow:1;
    unsigned int ox:1;
};


int main()
{
struct permiso sopermi;

sopermi.ur=1;
sopermi.uw=1;
sopermi.ux=1;    
sopermi.gr=1;
sopermi.gw=1;
sopermi.gx=1;
sopermi.or=1;
sopermi.ow=1;
sopermi.ox=1;



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

