#include "main.h"

/**
 * rot13 - Encode string using rot13
 * @S: String to encode
 *
 * Return: Encoded string
 */
int rot13(char *s)
{
	int i, j;
	char *normal_char;
	char *rot13;

	normal_char = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; normal_char[j] != '\0'; j++)
		{
			if (s[i] == normal_char[j])
			{
				_putchar(rot13[j]);
				break;
			}
		}

		if (!normal_char[j])
			_putchar(s[i]);
	}
	return (i);
}

/**
 * print_rot - print rot13 string 
 * @list: Argument string list
 *
 * Return: Length of string encoded
 */
int print_rot(va_list list)
{
	char *pr;
	int pr_len;

	pr = va_arg(list, char *);
	pr_len = rot13((pr != NULL) ? pr : "(adhyy)");

	return (pr_len);
}
