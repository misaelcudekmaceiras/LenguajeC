#include<stdio.h>
#include<stdlib.h>

int main (void){
   int stdbuff=10;
   int i=0;
   char cara;
   char * pcadena=0;

  pcadena=malloc(stdbuff*sizeof(char));

				while((cara= getchar())!='\n')
				{
						*(pcadena+i)=cara;
						i++;
						if(i>stdbuff)
						{
							pcadena =realloc(pcadena,i+1);
						}
				}
				*(pcadena+i)=0;
				printf("\n la cadena es %s \n",pcadena);
				free(pcadena);
return 0;
}
