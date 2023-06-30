#include "main.h"

/**
 * flag_checker - check for associated flags
 * @type: struct format type
 *
 * Return: flags
 
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
}*/

#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
