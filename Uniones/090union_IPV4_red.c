
#include <stdio.h>


union IP
	  {
	  char direcionip[16];//255.255.255.255  
	  struct
		{	
	      char octeto1[3];
	      char separador1;
	      char octeto2[3];
	      char separador2;
	      char octeto3[3];
	      char separador3;
	      char octeto4[3];
	      
	      int iocteto1;
	      int iocteto2;
	      int iocteto3;
	      int iocteto4;
		}direcionipchopeada;
};





int main()
{
   union IP miip;
   
   printf("Ingrese una direccion ip en formato xxx.xxx.xxx.xxx\n");
   scanf("%s",miip.direcionip);

   printf("La direccion ip es %s\n",miip.direcionip);
   
   miip.direcionipchopeada.separador1='\0';
   miip.direcionipchopeada.separador2='\0';
   miip.direcionipchopeada.separador3='\0';
   
printf("El primer  octeto de la direccion ip es %s\n",miip.direcionipchopeada.octeto1);
printf("El segundo octeto de la direccion ip es %s\n",miip.direcionipchopeada.octeto2);
printf("El tercer  octeto de la direccion ip es %s\n",miip.direcionipchopeada.octeto3);
printf("El cuarto  octeto de la direccion ip es %s\n",miip.direcionipchopeada.octeto4);

miip.direcionipchopeada.iocteto1=atoi(miip.direcionipchopeada.octeto1);
miip.direcionipchopeada.iocteto2=atoi(miip.direcionipchopeada.octeto2);
miip.direcionipchopeada.iocteto3=atoi(miip.direcionipchopeada.octeto3);
miip.direcionipchopeada.iocteto4=atoi(miip.direcionipchopeada.octeto4);


printf("Ahora los octetos los veo como enteros ;-) \n");

printf("El primer  octeto de la direccion ip es %d\n",miip.direcionipchopeada.iocteto1);
printf("El segundo octeto de la direccion ip es %d\n",miip.direcionipchopeada.iocteto2);
printf("El tercer  octeto de la direccion ip es %d\n",miip.direcionipchopeada.iocteto3);
printf("El cuarto  octeto de la direccion ip es %d\n",miip.direcionipchopeada.iocteto4);



   return 0; /* indica terminación exitosa */

} /* fin de main */




