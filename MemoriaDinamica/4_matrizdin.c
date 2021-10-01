

#include<stdio.h>
#include<stdlib.h>

int main (int argc,char * argv[])
{
    int f=0,c=0,ftot=0,ctot=0,i=0;
    char * pMatriz=0;
    int * pIntMatriz=0;
    
    if(argc<=2)
    {
        printf("Ingreso una cantidad de atributos invalida\n");
        return(0);
    }
    f=atoi(argv[1]);
    ftot=f;
    c=atoi(argv[2]);
    ctot=c;
    
    pMatriz=(char*)malloc(f*c*sizeof(int));
    pIntMatriz=(int*)pMatriz;
    if(pMatriz==NULL)
    {
        printf("Memoria Insuficiente\n");
        return(0);
    }
    
    for(i=0;i<(f*c*sizeof(int));i++)
    {
        *(pMatriz+i)=0;
    }
    
    for(f=0;f<ftot;f++)
    {
        for(c=0;c<ctot;c++)
        {
            printf("%d ",*(pIntMatriz+c+(f*ctot)) );
            
        }
        printf("\n" );
    }
    
    
    pIntMatriz=(int*)pMatriz;
    i=0;
        for(f=0;f<ftot;f++)
    {
        for(c=0;c<ctot;c++)
        {
            *(pIntMatriz+c+(f*ctot))=i;
            i++;
            
        }
        printf("\n" );
    }
    
    
        for(f=0;f<ftot;f++)
    {
        for(c=0;c<ctot;c++)
        {
            printf("%3d ",*(pIntMatriz+c+(f*ctot)) );
            
        }
        printf("\n" );
    }
    
    
    
    return(0);
}
