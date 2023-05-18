#include<stdio.h>

https://gcc.gnu.org/onlinedocs/gcc/Zero-Length.html

int main()
{
int b[0];
int a[]={};

printf("%p\n",a);
printf("%ld\n",sizeof(a));
printf("%p\n",b);
printf("%ld\n",sizeof(b));

return(0);
}
