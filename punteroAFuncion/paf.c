//R1091 Mariano Gonzalez  Misael Cudek
#include<stdio.h>

void mostrarhola(void);
void mostrarchau(void);


int  main(void){
  void(*puntero_a_mostrar)(void);
  
  mostrarhola();//aca usando la funcion como siempre
  mostrarchau();//aca usando la funcion como siempre
  
    
  puntero_a_mostrar=mostrarhola;
  puntero_a_mostrar();//aca usando el puntero a funcion
  
  puntero_a_mostrar=mostrarchau;
  puntero_a_mostrar();//aca usando el puntero a funcion
  
  
  
  return 0;
}



void mostrarhola (void){
  printf("HOLA\n"); 
}

void mostrarchau (void){
  printf("CHAU\n"); 
}
