#include "main.h"

/**
 * _strlen - Determine the length of string
 * @str: String
 *
 * Return: Length of string
 */
int _strlen(const char *str)
{
	int indx;

	for (indx = 0; str[indx] != 0; indx++)
		;
	return (indx);
}

/**
 * print - Handles char printing
 * @str: String
 *
 * Return: Length of string
 */
int print(char *str)
{
	int indx;

	for (indx = 0; str[indx] != '\0'; ++indx)
		_putchar(str[indx]);

	return (indx);
}

/**
  * is_printable - Check if a char is printable
  * @c: Char to check
  *
  * Return: 1 if c is printable, else 0

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
} */
