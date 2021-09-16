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
    printf("%c\n",s.tramita.v1[0]);
    printf("%c\n",s.tramita.v1[1]);
    printf("%c\n",s.tramita.v1[2]);
    printf("%c\n",s.tramita.v1[3]);
    
    printf("%c\n",s.tramita.sep1[0]);
    
    printf("%c\n",s.tramita.v2[0]);
    printf("%c\n",s.tramita.v2[1]);
    printf("%c\n",s.tramita.v2[2]);
    printf("%c\n",s.tramita.v2[3]);
    
    printf("%c\n",s.tramita.sep2[0]);
    
    printf("%c\n",s.tramita.v3[0]);
    printf("%c\n",s.tramita.v3[1]);
    printf("%c\n",s.tramita.v3[2]);
    printf("%c\n",s.tramita.v3[3]);
    
    printf("%c\n",s.tramita.sep3[0]);

return(0);
}
