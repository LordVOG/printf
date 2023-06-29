#include "main.h"

/**
 * print_string - Print string to stdout
 * @list: Argument list.
 *
 * Return: String length.
 */

int print_string(va_list list)
{
	char *pr;
	int pr_len;

	pr = va_arg(list, char*);
	pr_len = print((pr != NULL) ? pr : "(null)");

	return (pr_len);
}
