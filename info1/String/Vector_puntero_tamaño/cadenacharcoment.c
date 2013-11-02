#include <stdio.h>
#include<string.h>

int main()
{
   char qwerty[20];
   char qwerty2[20];
   char asdfg[] = "Informatica1"; 
   char * zxcvb=0;

   printf("Introduce un texto ");
   scanf( "%s", qwerty ); 
      
   printf("%c\n",qwerty[0]);
   printf("%s\n",asdfg);
   printf("%c\n",asdfg[2]);
   printf("%c\n",asdfg[8]);
   printf("%d\n",asdfg[12]);
   
   printf("%d\n", strlen(qwerty));
   printf("%d\n",sizeof(qwerty));
   printf("%d\n",sizeof(qwerty[3]));
   
   printf("%s\n",zxcvb);
   zxcvb=asdfg;
   printf("%s\n",zxcvb);
   
   qwerty2=qwerty;
   printf("%s\n",qwerty2);
   strcpy(qwerty2,qwerty);
   printf("%s\n",qwerty2);
   
   return 0; 

} 




