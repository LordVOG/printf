#include "main.h"

/**
 * print_hexadecimal_low - print number in hexadecimal
 * lowercase format eg. 0x23ae
 * @list: Number list
 *
 * Return: Number length
 */
int print_hexadecimal_low(va_list list)
{
	char *print_buff;
	int size;

	print_buff = itoa(va_arg(list, unsigned int), 16);

	size = print((print_buff != NULL) ? print_buff : "NULL");

	return (size);
}
