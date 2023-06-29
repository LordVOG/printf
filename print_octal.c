#include "main.h"

/**
 * print_octal - print unsigned octal to stdout
 * @list: Number list
 *
 * Return: Length of Number in octal
 */
int print_octal(va_list list)
{
	char *print_buff;
	int size;

	print_buff = itoa(va_arg(list, unsigned int), 8);

	size = print((print_buff != NULL) ? print_buff : "NULL");

	return (size);
}
