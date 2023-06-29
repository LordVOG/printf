#include "main.h"

/**
 * print_unsigned - Print a unsigned int
 * @list: String to print
 *
 * Return: Length of the number
 **/
int print_unsigned(va_list list)
{
	char *print_buff;
	int size;

	print_buff = itoa(va_arg(list, unsigned int), 10);

	size = print((print_buff != NULL) ? print_buff : "NULL");

	return (size);
}
