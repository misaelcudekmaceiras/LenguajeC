/* Figura 7.28: fig07_28.c
   Demostración de un arreglo de apuntadores a funciones */
#include <stdio.h>

/* prototipos */
void funcion1( int a );
void funcion2( int b );
void funcion3( int c );

int main()
{
   /* inicializa el arreglo de 3 apuntadores a funciones que toman cada una
      un argumento entero y devuelven void */
   void (*f[ 3 ])( int ) = { funcion1, funcion2, funcion3 };

   int eleccion; /* variable para almacenar la elección del usuario */

   printf( "Introduzca un numero entre 0 y 2, 3 para terminar: " );
   scanf( "%d", &eleccion );

   /* procesa la elección del usuario */
   while ( eleccion >= 0 && eleccion < 3 ) {

      /* invoca la función en la ubicación de la eleccion en el arreglo f y pasa
         la elección como argumento */
      (*f[ eleccion ])( eleccion );

      printf( "Introduzca un numero entre 0 y 2, 3 para terminar: ");
      scanf( "%d", &eleccion );
   } /* fin de while */

   printf( "Termina le ejecucion del programa.\n" );

   return 0; /* indica terminación exitosa */

} /* fin de main */

void funcion1( int a )
{
   printf( "Usted introdujo %d de manera que invoco a la funcion1\n\n", a );
} /* fin de la funcion1 */

void funcion2( int b )
{
   printf( "Usted introdujo %d de manera que invoco a la funcion2\n\n", b );
} /* fin de la funcion2 */

void funcion3( int c )
{
   printf( "Usted introdujo %d de manera que invoco a la funcion2\n\n", c );
} /* fin de la funcion3 */





