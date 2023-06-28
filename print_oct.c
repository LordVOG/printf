#include "main.h"

/**
 * print_undec - print unsigned octal digits
 * @o: format specifier
 *
 * Return: success
 */
int print_oct(va_list o)
{
	int index, n, length, powten, digit, num, count = 0;

	n = va_arg(o, unsigned int);
	if (n != 0)
	{
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
		for (index = 1; index <= length; index++)
		{
			digit = n / powten;
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
