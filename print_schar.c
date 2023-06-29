#include "main.h"

/**
  * print_schar - print single character on stdout
  * @c: char alias
  *
  * Return: success 0;
  */
int print_schar(va_list c)
{
	unsigned char my_char;

	my_char = va_arg(c, int);
	_putchar(my_char);
	return (1);
}

/**
  * print_percentage - prints format specifier
  *
  * Return: Success 0
  */
int print_percentage(void)
{
	_putchar('%');
	return (1);
}
