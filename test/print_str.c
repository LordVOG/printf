#include "main.h"

/**
  * print_str - print string of characters in single line
  * @s: string specifier
  *
  * Return: Success 0
  */
int print_str(va_list s)
{
	char *my_string;
	int index = 0;

	my_string = va_arg(s, char *);
	if (my_string == NULL)
		my_string = "(nil)";
	while (my_string[index])
	{
		_putchar(my_string[index]);
		index++;
	}
	return (index);
}
