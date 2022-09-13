#include<stdio.h>
#include<string.h>

struct persona
{
    char nombre[20];
    char apellido[20];
    int edad;
};

typedef struct persona persona;


int main ()
{
persona p1;
strcpy(p1.nombre,"saelmi");
strcpy(p1.apellido,"keduc");
p1.edad=36;    

printf("%s\n",p1.nombre);
printf("%s\n",p1.apellido);
printf("%d\n",p1.edad);

}


