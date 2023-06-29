#include "main.h"

int is_lowercase(char);
char *string_to_upper(char *);

/**
 * print_hexadecimal_upp - Print number in hexadecimal
 * uppercase format eg. 0X23EDR
 * @list: Number list
 *
 * Return: Number length in uppercase
 */
int print_hexadecimal_upp(va_list list)
{
	char *print_buff;
	int size;

	print_buff = itoa(va_arg(list, unsigned int), 16);
	print_buff = string_to_upper(print_buff);

	size = print((print_buff != NULL) ? print_buff : "NULL");

	return (size);
}

/**
 * is_lowercase - check if char are in lowercase
 * @c: Character
 *
 * Return: 1 or 0
 */
int is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * string_to_upper - change string of char to uppercase
 * @s: String
 *
 * Return: Uppercase string
 */
char *string_to_upper(char *s)
{
	int indx;

	for (indx = 0; s[indx] != '\0'; indx++)
	{
		if (is_lowercase(s[indx]))
			s[indx] -= 32;
	}

	return (s);
}

