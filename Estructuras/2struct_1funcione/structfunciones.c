#include<stdio.h>


  struct persona{
    
    char nombre[10];
    char sexo;
    int edad;
    char telefono[10];
    int * p;

  };
  
void llenarnombre(char *);  
  
int main (void){
  
int ivalor=0;
struct persona yo;
  
  
llenarnombre(&yo.nombre);
printf("Ingrese la edad\n");
scanf("%d",&yo.edad);;
printf("Ingrese el telefono\n");
scanf("%s",&yo.telefono);

printf("\n\n\nImpresion de valores\n\n\n");

printf("El nombre es %s \n",yo.nombre);
printf("El nombre es %d \n",yo.edad);
printf("El nombre es %s \n",yo.telefono);  
  return 0;
}

void llenarnombre (char * nombre){
  
  printf("Ingrese un nombre\n");
scanf("%s",nombre);
  
}
