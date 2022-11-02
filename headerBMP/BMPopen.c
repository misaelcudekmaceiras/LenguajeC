
#include <stdio.h>

#define headersize 54



union BMP
	  {
	  char header[headersize];
	  struct
		{	
	      char cTipoFichero[2];
	      char Tamano[4];
	      char reservado1[2];
	      char reservado2[2];
	      char InicioData[4];
	      char TamCabecera[4];
	      char AnchuraImagen[4];
	      char Anchura[4];
	      char Altura[4];
	      char NumPlanos[2];
	      char TamPuntos[2];
	      char Comprimido[4];
	      char TamImagen[4];
	      char ResolHoriz[4];
	      char ResolVert[4];
	      char TamTablaColor[4];
	      char ContColorImport[4];
		}BMPStrip;
};





int main(int argc, char ** argv )
{
   union BMP mibmp;
   int i=0;
   
   
   FILE * fdin= fopen(argv[1],"r");
   if(fdin==0)
   {printf("Error\n");
   return(1);
   }
   
   printf("Leo archiv archivo %s",argv[1]);
        i= fread( mibmp.header, headersize, 1, fdin );
        
         
         printf("\n lei %d bytes \n",i);
         
         mibmp.header[headersize]='\0';
         
        printf("Los char del header son\n"); 
         for(i=0;i<(headersize);i++)
         {
			 printf("%x",mibmp.header[i]);
		 }
		 
		 
		printf("\ncTipoFichero %c %c\n",mibmp.BMPStrip.cTipoFichero[0],mibmp.BMPStrip.cTipoFichero[1]);
		printf("El Tamano es %d\n",*(int *)mibmp.BMPStrip.Tamano);
		printf("Los datos inician en el byte InicioData %d\n",*(int *)mibmp.BMPStrip.InicioData);
		printf("El Tamano de la cabecera es es %d\n",*(int *)mibmp.BMPStrip.TamCabecera);
		printf("El Tamano del AnchuraImagen es %d\n",*(int *)mibmp.BMPStrip.AnchuraImagen);
		printf("El Tamano del Anchura es %d\n",*(int *)mibmp.BMPStrip.Anchura);
		printf("El Tamano del Altura Imagen es %d\n",*(int *)mibmp.BMPStrip.Altura);





   return (0); /* indica terminación exitosa */

} /* fin de main */







