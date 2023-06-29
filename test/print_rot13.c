#include "main.h"

/**
  * print_rot13 - encode string into rot13
  * @R: format specifier
  *
  * Return: success 0
  */
int print_rot13(va_list R)
{
	int i, j, count  = 0;
	char *rev;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	rev = va_arg(R, char *);
	if (rev == NULL)
		rev = "(nil)";
	for (j = 0; rev[j] != '\0'; j++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (rev[j] == input[i])
			{
				_putchar(output[i]);
				count++;
				break;
			}
		}
	}
	return (count);
}
