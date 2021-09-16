#include<stdio.h>
#include<string.h>

union miSeparador
{
    char cadena[16];
    struct trama
    {
        char v1[4];
        char sep1[1];
        char v2[4];
        char sep2[1];
        char v3[4];
        char sep3[1];
        char null[1];
        
    }tramita;
};

int main()
{
    union miSeparador s;
    
    strcpy(s.cadena,"Misa#1234#MiT_#");
    
    printf("%s\n",s.cadena);
    for(int i=0;i<4;i++)
    {
    printf("%c",s.tramita.v1[i]);    
    }
    printf("\t%c\t",s.tramita.sep1[0]);
    for(int i=0;i<4;i++)
    {
    printf("%c",s.tramita.v2[i]);    
    }
    printf("\t%c\t",s.tramita.sep2[0]);
    for(int i=0;i<4;i++)
    {
    printf("%c",s.tramita.v3[i]);    
    }
    
    printf("\t%c\n",s.tramita.sep3[0]);

return(0);
}
