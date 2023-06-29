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
