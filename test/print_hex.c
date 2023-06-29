#include "main.h"

/**
  * print_hex - print unsigned int in hexadecimal
  * @n: unsigned int to print
  * @c: printing case where 0=lowercase and 1=uppercase
  *
  * Return: output size
  */
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int index, length, powten, num, digit;
	int count = 0;
	char diff;

	if (n != 0)
	{
		num = n;
		length = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (num != 0)
		{
			num = num / 16;
			length++;
		}
		powten = 1;
		for (index = 1; index <= length - 1; index++)
			powten = powten * 16;
		for (index = 1; index <= length; index++)
		{
			digit = n / powten;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n = n - digit * powten;
			powten = powten / 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/**
  * print_lwhex - print unsigned hexadecimal in lowercase
  * @x: format specifier
  *
  * Return: success 0
  */
int print_lwhex(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}

/**
  * print_uphex - print unsigned hexadecimal in uppercase
  * @X: format specifier
  *
  * Return: success 0
  */
int print_uphex(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
