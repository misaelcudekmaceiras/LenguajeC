

#include<stdio.h>
#include<stdlib.h>

void* creameMatriz(int filasCant,int columnasCant,int tamDato);
void creameMatrizPaP(void**pp,int filasCant,int columnasCant,int tamDato);
void ponemeValorEnMatriz(void * pM,int cantColumnas,int f,int c,int valor);
void mostrarMatrizInt(void *pM,int filasCant,int columnasCant);

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
    

    //pMatriz=creameMatriz(f,c,sizeof(int));
    creameMatrizPaP((void*)&pIntMatriz,f,c,sizeof(int));
    
    //pIntMatriz=(int*)pMatriz;
    pMatriz=(char*)pIntMatriz;
    
    for(i=0;i<(f*c*sizeof(int));i++)
    {
        *(pMatriz+i)=0;
    }
    
   mostrarMatrizInt(pMatriz,ftot,ctot);
    
    
    pIntMatriz=(int*)pMatriz;
    
    i=0;
        for(f=0;f<ftot;f++)
    {
        for(c=0;c<ctot;c++)
        {
            ponemeValorEnMatriz(pIntMatriz,ctot,f,c,i);
            i++;
        }
        printf("\n" );
    }
    
    
    mostrarMatrizInt(pMatriz,ftot,ctot);
    
    
    
    return(0);
}


void creameMatrizPaP(void**pp,int filasCant,int columnasCant,int tamDato)
{
	 (*pp)=malloc(filasCant*columnasCant*tamDato);
	 if((*pp)==NULL)
	{
		 printf("Error Mem Insuficiente\n");
	}
}



void ponemeValorEnMatriz(void * pM,int cantColumnas,int f,int c,int valor)
{
    *(((int*)pM)+c+(f*cantColumnas))=valor; 
    //con el casteo lo tranformo para el tipo de puntero que quiero manejar y me sirve para matrices
    //del tipo de dato que yo quiera
}

void* creameMatriz(int filasCant,int columnasCant,int tamDato)
{
    char * pMatriz=0;
    pMatriz=(char*)malloc(filasCant*columnasCant*tamDato);

        if(pMatriz==NULL)
    {
        printf("Memoria Insuficiente\n");
        return(0);
    }
    else
    {
        return(pMatriz);
    }
    
}

void mostrarMatrizInt(void * pIntMatriz,int filasCant,int columnasCant)
{
    int f=0,c=0;
    for(f=0;f<filasCant;f++)
    {
        for(c=0;c<columnasCant;c++)
        {
            printf("%3d ",*(((int*)pIntMatriz)+c+(f*columnasCant)) );
            
        }
        printf("\n" );
    }
    
}

        
