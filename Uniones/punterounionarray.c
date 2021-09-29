#include<stdio.h>
#include<stdlib.h>

union variablesUnidas
{
    int *p;
    char bytesdelint[8];
};

int main()
{
    union variablesUnidas v;

    v.p=(int*)malloc(3);

    
    printf("%p\n",v.p);
    for(int i=0;i<8;i++)
    {
    printf("%c_%x\t",v.bytesdelint[i],(unsigned char )v.bytesdelint[i]);    
    }
    printf("\n");
    
    free(v.p);
    
return(0);
}
