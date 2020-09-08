
#include <stdio.h>

/* la función main comienza la ejecución del programa */
int main()
{
char cadena1[ 20 ]; 
char cadena2[] = "literal de cadena"; 
int i; 


printf("Introduce una cadena: ");
scanf( "%s", cadena1 ); 


printf( "La cadena1 es: %s\ncadena2 es: %s\n"
"La cadena1 con espacios entre caracteres es:\n",
cadena1, cadena2 );


for ( i = 0; cadena1[ i ] != '\0'; i++ ) {
										printf( "%c ", cadena1[ i ] );
										} 

printf( "\n" );

return 0; 

}



