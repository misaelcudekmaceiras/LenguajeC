#include <stdio.h>

int fcontar(int);
int fpotencia(int);
void DecaBin(int, int, int);

int main()
{
  int valDec=0, cont=0;
  
  printf("\n\n");
  
  printf("ingrese un número decimal:\n");
  scanf("%d", &valDec);
  
  cont=fcontar(valDec);
  DecaBin(cont, valDec, valDec);
   
  return 0;
}

int fcontar(int valor)
{
  int cuenta=0;
  
  while(valor>1)
  {
    valor=(valor/2);
    cuenta++;
  }
  
  return cuenta;
}

int fpotencia(int indice)
{
  int n=2;
  
  for(indice; indice>1; indice--)
  {
    n=n*2;
  }
  
  return n;
}

void DecaBin(int contador, int resto, int cociente)
{
  int n=0;
  n=fpotencia(contador);
  printf("El valor binario de %d es:\n",cociente);
  
  for(contador; contador>0; contador--)
 {
   resto=(cociente%n);
   cociente=(cociente/n);
   n=(n/2);
   printf("%d",cociente);
   cociente=resto;
 }
 printf("%d",resto);
 printf("\n\n");
   
}
  