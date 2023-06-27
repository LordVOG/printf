#include "main.h"

/**
 * if_printable - Checks if a character is printable
 * @b: the character to be checked.
 *
 * Return: 1 if printable and 0 if otherwise
 */
int if_printable(char b)
{
	if (b >= 32 && b < 127)
		return (1);

	return (0);
}

/**
 * add_hex_num - Adds hexadecimal code to buffer
 * @buffer: Array of chars.
 * @a: Index at which to start appending.
 * @asc_code: ASSCI CODE.
 * Return: Always 3
 */
int add_hex_num(char asc_code, char buffer[], int a)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format is two digits long */
	if (asc_code < 0)
		asc_code *= -1;

	buffer[a++] = '\\';
	buffer[a++] = 'x';

	buffer[a++] = map_to[asc_code / 16];
	buffer[a] = map_to[asc_code % 16];

	return (3);
}

/**
 * if_digit - Checks if a character is a digit
 * @b: the character to be checked
 * Return: 1 if digit, 0 otherwise
 */
int if_digit(char b)
{
	if (b >= '0' && b <= '9')
		return (1);

	return (0);
}

/**
 * post_size_number - Post a number to a specific size
 * @num1: the number to be posted
 * @size: size of the type to be casted
 *
 * Return: Posted value of the num1
 */
long int post_size_number(long int num1, int size)
{
	if (size == S_LONG)
		return (num1);
	else if (size == S_SHORT)
		return ((short)num1);

	return ((int)num1);
}

/**
 * post_size_unsgned - Post a number to a specific size
 * @num1: the number to be posted
 * @size: size of the type to be posted
 *
 * Return: posted value of num1
 */
long int post_size_unsgned(unsigned long int num1, int size)
{
	if (size == S_LONG)
		return (num1);
	else if (size == S_SHORT)
		return ((unsigned short)num1);

	return ((unsigned int)num1);
}
