#include "main.h"

/**
  * print_bin - print binary digits eg. 01101
  * @b: binary specifier
  *
  * Return: Success 0
  */
int print_bin(va_list b)
{
	int index, n, length, powten, digit, num;
	int count = 0;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		num = n;
		length = 0;
		while (num != 0)
		{
			num = num / 2;
			length++;
		}
		powten = 1;
		for (index = 1; index <= length - 1; index++)
			powten = powten * 2;
		for (index = 1; index <= length; index++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n = n - digit * powten;
			powten = powten / 2;
		}
	}
	else
	{
		_putchar('0');
		return (0);
	}
	return (count);
}
