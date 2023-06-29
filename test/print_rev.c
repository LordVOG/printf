#include "main.h"

/**
  * print_rev - print text in reverse
  * @r: format specifier
  *
  * Return: Success 0
  */
int print_rev(va_list r)
{
	char *str;
	int indx, indx1 = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (indx = 0; str[indx] != '\0'; indx++)
		;
	for (indx -= 1; indx >= 0; indx--)
	{
		_putchar(str[indx]);
		indx1++;
	}
	return (indx1);
}
