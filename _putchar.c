#include "main.h"

/**
 * _putchar - write characters to stdout
 * @c: Character to print
 *
 * Return: Success 1 
 * On error, -1 is return, and errno is set appropriately
 */
int _putchar(char c)
{
	return (buffer(c));
}

/**
 * buffer - Save character in buffer
 * @c: Character in focus
 *
 * Return: 1
 */
int buffer(char c)
{
	static char buffering[1024];
	static int indx;

	if (c == -1 || indx == 1024)
	{
		write(1, buffering, indx);
		indx = 0;
	}

	if (c != -1)
		buffering[indx++] = c;

	return (1);
}
