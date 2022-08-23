//R1091 Mariano Gonzalez  Misael Cudek
#include<stdio.h>

int sumaint(int,int);



int  main(void){
  int resu=0;
  int(*puntero_a_funcion1)(int,int);
  int(*puntero)(char *);
  
  char mensaje[]="Eliot casa telefono\n";

  puntero_a_funcion1=sumaint;
  puntero=printf;// si se puede tener un puntero a una funcion del lenguaje
  
  resu=puntero_a_funcion1(5,8);// con el puntero llamo a la funcion sumaint
  
  printf("El valor de la suma es %d\n\n",resu);
  
  puntero(mensaje);// con el puntero llamo a printf
  
  return 0;
}


int sumaint(int num1,int num2){
  return (num1+num2);    
}

