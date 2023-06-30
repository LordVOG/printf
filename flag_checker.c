#include "main.h"

/**
 * flag_checker - check for associated flags
 * @type: struct format type
 *
 * Return: flags
 */
int flag_checker(char type)
{
	switch (type)
	{
		case '+':
			return (1);
		case ' ':
			return (2);
		case '#':
			return (3);
		case 'l':
			return (4);
		case 'h':
			return (5);
		default:
			return (0);
	}
	return (0);
}
