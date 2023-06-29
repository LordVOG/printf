#include "main.h"

/**
 * print_rev_string - print char string in reverse
 * @list: Arguments list
 *
 * Return: Length of string
 */
int print_rev_string(va_list list)
{
	int indx, size;
	const char *str;

	str = va_arg(list, const char *);

	size = _strlen(str);

	for (indx = size - 1; indx >= 0; indx--)
		_putchar(str[indx]);
	return (size);
}
