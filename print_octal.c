#include "main.h"

/**
 * print_undec - print unsigned octal digits
 * @o: format specifier
 *
 * Return: success
 */
int print_octal(va_list o)
{
	unsigned int index, n, length, powten, digit, num;
	int count = 0;

	n = va_arg(o, unsigned int);
	if (n != 0)
	{
		num = n;
		length = 0;
		while (num != 0)
		{
			num = num / 8;
			length++;
		}
		powten = 1;
		for (index = 1; index <= length - 1; index++)
			powten = powten * 8;
		for (index = 1; index <= length; index++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n = (n - digit) * powten;
			powten = powten / 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
