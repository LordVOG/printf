#include "main.h"

/**
 * print_binary - Prints number in base 2
 * @list: List of numbers to print in base 2
 *
 * Return: Number length in binary
 */
int print_binary(va_list list)
{
	char *print_buff;
	int size;

	print_buff = itoa(va_arg(list, unsigned int), 2);

	size = print(print_buff);

	return (size);
}
