#include<stdio.h> /* para printf */
#include<stdlib.h>
#include<string.h> /* para strlen */

int
main(int argc, char **argv)
{
	int n;
	int fd[2];
	char buf[1025];
	char *data = "Hola... este es un dato de ejemplo!";

	pipe(fd);
	write(fd[1], data, strlen(data));
	if((n = read (fd[0], buf, 1024)) >= 0) {
		buf[n] = 0; /* termina el string */
		printf("lee %d bytes desde el pipe: \"%s\"\n", n, buf);
						}
	else
		perror("leer");

	exit(0);
}
