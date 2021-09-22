#include<stdio.h>

  struct persona{
	char a[4096*2];
	int b;
	char aa[4096*3];
  };
  
int main (void){
  
//int ivalor=0;
struct persona yo;// <struct tipo> <nombre>;
printf("%ld\n",sizeof(yo.a));
printf("%ld\n",sizeof(yo.b));
printf("%ld\n",sizeof(yo.aa));
printf("///////////\n");
printf("%ld\n",sizeof(struct persona));
printf("Direciones\n");
printf("&yo %p\n",&yo);
printf("%p\n",&(yo.a));
printf("%p\n",&(yo.b));
printf("%p\n",&(yo.aa));


 
  return 0;
}

