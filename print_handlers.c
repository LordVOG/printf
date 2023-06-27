#include "main.h"

/* WRITE HANDLE **/
/**
 * handle_print_char - to print a string
 * @b: character type.
 * @buffer: Array buffer to handle print
 * @flag:  Determines active flags
 * @width: Gives the width.
 * @precise: precision specifier
 * @size: Specifies size
 *
 * Return: CHaracters printed
 */
int handle_print_char(char b, char buffer[],
	int flag, int width, int precise, int size)
{ /* character is stored at left */
	int a = 0;
	char paddin = ' ';

	UNUSED(precise);
	UNUSED(size);

	if (flag & F_ZERO)
		paddin = '0';

	buffer[a++] = b;
	buffer[a] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFF_SIZE - a - 2] = paddin;

		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/* PRINT A NUMBER */
/**
 * print_number - Function prints a string
 * @to_neg: Argument list
 * @end: specified character types.
 * @buffer: Array to handle print
 * @flag:  Determines active flags
 * @width: Gives the sidth.
 * @precise: specifies precision
 * @size: Specifies size
 *
 * Return: total chars printed.
 */
int print_number(int to_neg, int end, char buffer[],
	int flag, int width, int precise, int size)
{
	int len = BUFF_SIZE - end - 1;
	char paddin = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		paddin = '0';
	if (to_neg)
		extra_ch = '-';
	else if (flag & F_PLUS)
		extra_ch = '+';
	else if (flag & F_SPACE)
		extra_ch = ' ';

	return (print_number(end, buffer, flag, width, precise,
		len, paddin, extra_ch));
}

/**
 * print_num - Use buffer to write a number
 * @end: Start point at the buffer
 * @buffer: Buffer
 * @flag: the flags
 * @width: width
 * @precise: specifies precision
 * @len: length of the number
 * @paddin: Pading character
 * @extra_c: Extra character
 *
 * Return: Total printed chars
 */
int print_num(int end, char buffer[],
	int flag, int width, int precise,
	int len, char paddin, char extra_c)
{
	int a, paddin_start = 1;

	if (precise == 0 && ind == BUFF_SIZE - 2 && buffer[end] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precise == 0 && ind == BUFF_SIZE - 2 && buffer[end] == '0')
		buffer[end] = paddin = ' '; /* width to display plus padding ' ' */
	if (precise > 0 && precise < len)
		paddin = ' ';
	while (precise > len)
		buffer[--end] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (a = 1; a < width - len + 1; a++)
			buffer[a] = paddin;
		buffer[a] = '\0';
		if (flag & F_MINUS && paddin == ' ')/* Extra char to left  buffer */
		{
			if (extra_c)
				buffer[--end] = extra_c;
			return (write(1, &buffer[end], len) + write(1, &buffer[1], a - 1));
		}
		else if (!(flag & F_MINUS) && paddin == ' ')/*char left buffer*/
		{
			if (extra_c)
				buffer[--end] = extra_c;
			return (write(1, &buffer[1], a - 1) + write(1, &buffer[end], len));
		}
		else if (!(flag & F_MINUS) && paddin == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], a - padd_start) +
				write(1, &buffer[ind], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--end] = extra_c;
	return (write(1, &buffer[end], len));
}

/**
 * print_unsgnd - Prints unsigned number
 * @if_negative: shows if number is negative
 * @end: start point index at the buffer
 * @buffer: Character arrays
 * @flag: specifies flags
 * @width: specifies width
 * @precise: specifies precision
 * @size: specifies size
 *
 * Return: total chars printed
 */
int print_unsgnd(int if_negative, int end,
	char buffer[],
	int flag, int width, int precise, int size)
{
	/* The num stored at right of buffer and starts at position a */
	int len = BUFF_SIZE - end - 1, a = 0;
	char paddin = ' ';

	UNUSED(if_negative);
	UNUSED(size);

	if (precise == 0 && end == BUFF_SIZE - 2 && buffer[end] == '0')
		return (0); /* printf(".0d", 0)  no char printed */

	if (precise > 0 && precise < len)
		paddin = ' ';

	while (precise > len)
	{
		buffer[--end] = '0';
		len++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		paddin = '0';

	if (width > len)
	{
		for (a = 0; a < width - len; a++)
			buffer[a] = paddin;

		buffer[a] = '\0';

		if (flag & F_MINUS) /* Puts extra char to buffer left*/
		{
			return (write(1, &buffer[end], len) + write(1, &buffer[0], a));
		}
		else /* Puts extra character to the left of padding*/
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[end], len));
		}
	}

	return (write(1, &buffer[end], len));
}

/**
 * print_pointer - Print address
 * @buffer: Character array
 * @end: The start of the address
 * @len: number length
 * @width: specifies the width
 * @flag: specifies the flag
 * @paddin: character to indicate the padding
 * @extra_c: Extra character
 * @paddin_start: Index at which padding should start
 *
 * Return: Total writen characters.
 */
int print_pointer(char buffer[], int end, int len,
	int width, int flag, char paddin, char extra_c, int paddin_start)
{
	int a;

	if (width > len)
	{
		for (a = 3; a < width - len + 3; a++)
			buffer[a] = paddin;
		buffer[a] = '\0';
		if (flag & F_MINUS && paddin == ' ')/* Asign char to the left buffer */
		{
			buffer[--end] = 'x';
			buffer[--end] = '0';
			if (extra_c)
				buffer[--end] = extra_c;
			return (write(1, &buffer[end], len) + write(1, &buffer[3], a - 3));
		}
		else if (!(flag & F_MINUS) && paddin == ' ')/* Buffer extra char to left */
		{
			buffer[--end] = 'x';
			buffer[--end] = '0';
			if (extra_c)
				buffer[--end] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[end], len));
		}
		else if (!(flag & F_MINUS) && paddin == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--paddin_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[paddin_start], a - paddin_start) +
				write(1, &buffer[end], length - (1 - paddin_start) - 2));
		}
	}
	buffer[--end] = 'x';
	buffer[--end] = '0';
	if (extra_c)
		buffer[--end] = extra_c;
	return (write(1, &buffer[end], BUFF_SIZE - end - 1));
}
