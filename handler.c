#include "main.h"

/**
 * handler - The format controller
 * @str: String format
 * @list: Argument list
 *
 * Return: Total size of argument with the total size of base string
 */
int handler(const char *str, va_list list)
{
	int size, indx, out;

	size = 0;
	for (indx = 0; str[indx] != 0; indx++)
	{
		if (str[indx] == '%')
		{
			out = percent_handler(str, list, &indx);
			if (out == -1)
				return (-1);

			size += out;
			continue;
		}
		_putchar(str[indx]);
		size += 1;
	}
	return (size);
}

/**
 * percent_handler - Percentage format controller
 * @str: String format
 * @list: Argument lists
 * @i: Iterator
 *
 * Return: Size of elements printed
 */
int percent_handler(const char *str, va_list list, int *i)
{
	int size, indx, number_formats;
	format formats[] = {
		{'s', print_string},
		{'c', print_char},
		{'d', print_integer},
		{'i', print_integer},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexadecimal_low},
		{'X', print_hexadecimal_upp},
		{'p', print_pointer},
		{'r', print_rev_string},
		{'R', print_rot}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (size = indx = 0; indx < number_formats; indx++)
	{
		if (str[*i] == formats[indx].type)
		{
			size = formats[indx].f(list);
			return (size);
		}
	}
	_putchar('%'), _putchar(str[*i]);
	return (2);
}
