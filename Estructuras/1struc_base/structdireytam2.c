#include<stdio.h>

  struct persona{
	char a;
	int b;
	char aa;
	int bb;
	char aaa;
	int bbb;
  };
  
int main (void){
  
//int ivalor=0;
struct persona yo;// <struct tipo> <nombre>;
printf("%ld\n",sizeof(yo.a));
printf("%ld\n",sizeof(yo.b));
printf("%ld\n",sizeof(yo.aa));
printf("%ld\n",sizeof(yo.bb));
printf("%ld\n",sizeof(yo.aaa));
printf("%ld\n",sizeof(yo.bbb));

printf("///////////\n");
printf("%ld\n",sizeof(struct persona));
printf("Direciones\n");
printf("&yo %p\n",&yo);
printf("%p\n",&(yo.a));
printf("%p\n",&(yo.b));
printf("%p\n",&(yo.aa));
printf("%p\n",&(yo.bb));
printf("%p\n",&(yo.aaa));
printf("%p\n",&(yo.bbb));

 
  return 0;
}

