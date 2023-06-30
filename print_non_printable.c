#include "main.h"

/**
 * print_non_printable - Print ascii code in hexadecimal
 * for non printable char
 * @list: char list
 *
 * Return: Number length in uppercase
 */
int print_non_printable(va_list list)
{
	int i = 0, length = 0;
	char *buff;

	buff = va_arg(list, char *);

	if (!buff)
		return (print("(null)"));
	while (buff[i])
	{
		if ((0 < buff[i] && buff[i] < 32) || buff[i] >= 127)
		{
			length += (buff[i] < 16) ? print("\\0x") : print("\\x");
			i++;
			continue;
		}
		length += _putchar(buff[i]);
		i++;
	}

	return (length);
}
			
