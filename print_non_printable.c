#include "main.h"

/**
 * print_non_printable - Print ascii code in hexadecimal
 * for non printable char
 * @list: char list
 *
 * Return: Number length in uppercase
 */
int print_non_printable(va_list list)
{
	char *print_buff;
	int size;

	print_buff = va_arg(list, char *);
	if (print_buff == NULL)
		print_buff = "(null)";
	size = is_printable((print_buff != NULL) ? print_buff : "(null)");

	return (size);
}

