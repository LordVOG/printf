#include "main.h"

/**
  * find_format - function pointer that looks up for _printf
  * format type and print corresponding types to screen
  * @format: available formats int, char, float, double
  *
  * Return: associated result or NULL
  */
int (*find_format(const char *format))(va_list)
{
	unsigned int index = 0;
	f_type specifiers[] = {
		{"c", print_schar},
		{"d", print_dec},
		{"f", print_float},
		{"s", print_str},
		{"i", print_int},
		{"o", print_octal},
		{"u", print_undec},
		{"x", print_lwhex},
		{"X", print_uphex},
		{"b", print_bin},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (specifiers[index].fsc)
	{
		if (specifiers[index].fsc[0] == (*format))
			return (specifiers[index].func);
		index++;
	}
	return (NULL);
}

/**
  * _printf - function that produce output according to a format string
  * @format: format string
  *
  * Return: format output
  */
int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int index, cprint = 0;
	int (*func)(va_list);

	if (format == NULL)
		return (1);

	va_start(ap, format);
	while (format[index])
	{
		if (format[index] != '%' && format[index])
		{
			_putchar(format[index]);
			index++;
			cprint++;
		}
		if (format[index] == '\0')
			return (cprint);
		func = find_format(&format[index + 1]);

		if (func != NULL)
		{
			cprint = cprint + func(ap);
			index = index + 2;
			continue;
		}
		if (!format[index + 1])
			return (1);
		_putchar(format[index]);
		cprint++;
		if (format[index + 1] == '%')
			index = index + 2;
		else
			index++;
	}
	va_end(ap);
	return (cprint);
}
