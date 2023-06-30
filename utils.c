#include "main.h"

/**
 * _strlen - Determine the length of string
 * @str: String
 *
 * Return: Length of string
 */
int _strlen(const char *str)
{
	int indx;

	for (indx = 0; str[indx] != 0; indx++)
		;
	return (indx);
}

/**
 * print - Handles char printing
 * @str: String
 *
 * Return: Length of string
 */
int print(char *str)
{
	int indx;

	for (indx = 0; str[indx] != '\0'; ++indx)
		_putchar(str[indx]);

	return (indx);
}

/**
 * convert_base - converts & prints a number into the given base
 * @n: number to convert
 * @base: base to use
 * @c: char
 *
 * Return: length of the printed number
 */
int convert_base(unsigned long n, int base, char c)
{
	int len = 0;

	if (n / base)
		len += convert_base(n / base, base, c);

	if (n % base > 9)
		len += _putchar(n % base + c);
	else
		len += _putchar((n % base) + '0');

	return (len);
}
