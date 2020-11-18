    #include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char buffer[200];
int pipename[2];
int main(int argc, char *argv[])
{
  int rc;
  char buf[200];
  unsigned char buflenHijo;
  unsigned char buflenPadre;
  pipe(pipename);
  rc = fork();
  if (rc == 0)
  {               /* HIJO */
    close(pipename[0]);   /* CIERRO EXTREMO DE LECTURA */
    for (;;)
    {
      gets(buf);
      buflenHijo = (unsigned char)strlen(buf);
//      printf("HIJO: %d\n", (int)buflenHijo);
      write(pipename[1], &buflenHijo, 1);  /* ENVIO LONGITUD DEL BUFFER */
      write(pipename[1], buf, buflenHijo); /* ENVIO BUFFER */
    }
  }
  else
  {               /* PADRE */
    close(pipename[1]);   /* CIERRO EXTREMO DE ESCRITURA */
    for (;;)
    {
      read(pipename[0], &buflenPadre, 1);  /* LEO LONGITUD DEL BUFFER */
//      printf("PADRE: %d\n", (int)buflenPadre);
      read(pipename[0], buffer, buflenPadre);  /* LEO BUFFER */
      printf("%s\n", buffer);
    }
  }
}
