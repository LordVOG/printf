#include "main.h"

/**
 * _printf - produces output according to a format specified
 * @format: Character string. The format string
 * is composed of zero or more directives
 *
 * Return: The number of characters printed (exclusding the
 * null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int size;
	va_list ap;

	if (format == NULL)
		return (-1);

	size = _strlen(format);
	if (size <= 0)
		return (0);

	va_start(ap, format);
	size = handler(format, ap);

	_putchar(-1);
	va_end(ap);

	return (size);
}
