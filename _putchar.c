#include <unistd.h>

/**
  * _putchar - write character in c to stdout
  * @c: Character to print
  *
  * Return: Success 0 else return 1
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
