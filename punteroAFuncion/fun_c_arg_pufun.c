//R1091 Mariano Gonzalez  Misael Cudek
#include<stdio.h>

int sumaint(int,int);//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int funcion(int(*) (int,int),int,int);//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int  main(void){
  int resu=0;
  int num1=3;
  int num2=4;
  
  int(*puntero_a_funcion1)(int,int); //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  
  puntero_a_funcion1=sumaint;//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

resu = funcion(puntero_a_funcion1,num1,num2);//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
printf("El valor es %d",resu);
    
  return 0;
}


int sumaint(int num1,int num2){
  return (num1+num2);    
}

int funcion(int pfun(int,int),int n1,int n2){//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	int result=0;
	result=pfun(n1,n2);//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	
	return result;//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	}
