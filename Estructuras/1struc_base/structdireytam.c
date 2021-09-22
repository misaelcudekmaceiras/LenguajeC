#include<stdio.h>

  struct persona{
    char nombre[10];
    char sexo;
    int edad;
    char telefono[10];
    int * p;
  };
  
int main (void){
  
//int ivalor=0;
struct persona yo;// <struct tipo> <nombre>;
printf("%ld\n",sizeof(yo.nombre));
printf("%ld\n",sizeof(yo.sexo));
printf("%ld\n",sizeof(yo.edad));
printf("%ld\n",sizeof(yo.telefono));
printf("%ld\n",sizeof(yo.p));
printf("///////////\n");
printf("%ld\n",sizeof(struct persona));
printf("Direciones\n");
printf("&yo %p\n",&yo);
printf("&(yo.nombre[0]) %p\n",&(yo.nombre[0]));
printf("&(yo.sexo) %p\n",&(yo.sexo));
printf("&(yo.edad) %p\n",&(yo.edad));
printf("&(yo.telefono[0]) %p\n",&(yo.telefono[0]));
printf("&(yo.p) %p\n",&(yo.p));
 
  return 0;
}

