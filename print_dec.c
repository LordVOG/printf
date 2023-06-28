#include "main.h"

/**
  * print_dec - print decimal in base 10
  * @d: decimal specifier
  *
  * Return: Success 0
  */
int print_dec(va_list d)
{
	int index, n, length, powten, digit, num, count = 0;

	n = va_arg(d, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		num = n;
		length = 0;
		while (num != 0)
		{
			num = num / 10;
			length++;
		}
		powten = 1;
		for (index = 1; index <= length - 1; index++)
			powten = powten * 10;
		for (index = 1; index < length; index++)
		{
			digit = n / powten;

			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n = n - digit * powten;
			powten = powten / 10;
		}
	}
	else
	{
		_putchar('0');
		return (0);
	}
	return (count);
}
