#include "main.h"

/**
 * print_integer - print number in base 10 to stdout
 * @list: number list
 *
 * Return: Length of decimal number
 */
int print_integer(va_list list)
{
	char *print_buff;
	int size;

	print_buff = itoa(va_arg(list, int), 10);

	size = print((print_buff != NULL) ? print_buff : "NULL");

	return (size);
}
