#include "main.h"

/**
 * print_undec - print unsigned decimal
 * @u: format specifier
 *
 * Return: success
 */
int print_undec(va_list u)
{
	int index, n, length, powten, digit, num;
	int count = 0;

	n = va_arg(u, unsigned int);
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
