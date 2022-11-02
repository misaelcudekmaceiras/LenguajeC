#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define TamCabezera 54

#pragma pack(1)

union Cabezera
{
char Header[TamCabezera]; 	
struct CabezeraFormateada
{
	char TipoArchivo[2];
	int TamARchivo;
	short int Reservado1;
	short int Reservado2;
	int InicioImagen;
	int TamTotalCabezera;
	int Ancho;
	int Altura;
	short int NumPlanos;
	short int TamPunto;
	int Compresion;
	int TamImg;
	int ResoHorizontal;
	int ResoVertical;
	int TamTablaColores;
	int ContColores;
}DatosFormateados;
};
#pragma pack(4)

int main(int argc, char *argv[])
{
	union Cabezera DatosBMP;
	int fd_in;
	printf("%li\n",sizeof(DatosBMP));
	
	
	if(argc<2)
  {
    printf("falta imagen\n");
    return(0);
  }
  
	fd_in=open(argv[1],O_RDONLY);
		
	read(fd_in,DatosBMP.Header,TamCabezera);
	
	printf("Tipo de Archivo: %c%c\n",DatosBMP.DatosFormateados.TipoArchivo[0],DatosBMP.DatosFormateados.TipoArchivo[1]);
	printf("Tamaño de archivo: %d\n",DatosBMP.DatosFormateados.TamARchivo);
	printf("Reservado1:%d\n",DatosBMP.DatosFormateados.Reservado1);
	printf("Reservado2:%d\n",DatosBMP.DatosFormateados.Reservado2);
	printf("Inicio de la Imagen:%d\n",DatosBMP.DatosFormateados.InicioImagen);
	printf("Tamaño Total de la Cabecera:%d\n",DatosBMP.DatosFormateados.TamTotalCabezera);
	printf("Ancho de la Imagen:%d\n",DatosBMP.DatosFormateados.Ancho);
	printf("Altura de la Imagen:%d\n",DatosBMP.DatosFormateados.Altura);
	printf("Numero de Planos:%d\n",DatosBMP.DatosFormateados.NumPlanos);
	printf("Tamaño del Punto:%d\n",DatosBMP.DatosFormateados.TamPunto);
	printf("Compresión:%d\n",DatosBMP.DatosFormateados.Compresion);
	printf("Tamaño de la Imagen:%d\n",DatosBMP.DatosFormateados.TamImg);
	printf("Resolución Horizontal:%d\n",DatosBMP.DatosFormateados.ResoHorizontal);
	printf("Resolución Vertical:%d\n",DatosBMP.DatosFormateados.ResoVertical);
	printf("Tamaño Tabla de Colores:%d\n",DatosBMP.DatosFormateados.TamTablaColores);
	printf("Contador de Colores:%d\n",DatosBMP.DatosFormateados.ContColores);
	
	
	close(fd_in);	
	return 0;
	
}

	
