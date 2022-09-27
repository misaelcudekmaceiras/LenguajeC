#include<stdio.h>
#include<string.h>

struct permiso
{
    unsigned short int ur;
    unsigned short int uw;
    unsigned short int ux;
    
    unsigned short int gr;
    unsigned short int gw;
    unsigned short int gx;
    
    unsigned short int or;
    unsigned short int ow;
    unsigned short int ox;
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

