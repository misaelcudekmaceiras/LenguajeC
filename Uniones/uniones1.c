#include<stdio.h>

union variablesUnidas
{
    int i;
    char bytesdelint[4];
};

int main()
{
    union variablesUnidas v;

    v.i=0x0054494D;
    printf("%d\n",v.i);
    printf("%c\n",v.bytesdelint[0]);
    printf("%c\n",v.bytesdelint[1]);
    printf("%c\n",v.bytesdelint[2]);
    printf("%c\n",v.bytesdelint[3]);

    printf("%s\n",v.bytesdelint);
return(0);
}
