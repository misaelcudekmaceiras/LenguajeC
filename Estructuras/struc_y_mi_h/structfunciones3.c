#include<stdio.h>
#include "mipuntohstruc.h"

  struct persona{
    
    char nombre[10];
    char sexo[1];
    int edad;
    char telefono[10];
    int * p;
//    struct persona * psig;
//    struct persona * pant;
  };
  
// void llenarnombre(char *);  
// void llenaredad(int*);
// void llenarsexo(char *);
// void llenartelefono(char *);

int main (void){
  
int ivalor=0;
struct persona yo;
  
  
llenarnombre(&yo.nombre);
llenaredad(&yo.edad);
llenarsexo(&yo.sexo);
llenartelefono(&yo.telefono);




printf("\n\n\nImpresion de valores\n\n\n");

printf("El nombre es %s \n",yo.nombre);
printf("El nombre es %d \n",yo.edad);
printf("El nombre es %s \n",yo.sexo);
printf("El nombre es %s \n",yo.telefono);  
  return 0;
}

//Despues del main van las funciones


void llenarnombre (char * pnombre){
  
  printf("Ingrese un nombre\n");
scanf("%s",pnombre);
  
}

void llenaredad (int * pedad){
  
  printf("Ingrese la edad\n");
scanf("%d",pedad);
  
}

void llenarsexo (char * psexo){
  
  printf("Ingrese el sexo\n");
scanf("%s",psexo);
  
}

void llenartelefono (char * ptelefono){
  
  printf("Ingrese el telefono\n");
scanf("%s",ptelefono);
  
}





