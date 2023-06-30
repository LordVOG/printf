#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/** utils.c **/
int _strlen(const char *);
int print(char *);
char *itoa(long int, int);

/** printf.c **/
int _printf(const char *, ...);

/** handler.c **/
int handler(const char *, va_list);
int percent_handler(const char *, va_list, int *);

/** _putchar.c **/
int _putchar(char);
int buffer(char);

/** Flag Checker **/
int flag_checker(char type);

/** printers **/
int print_string(va_list);
int print_char(va_list);
int print_integer(va_list);
int print_binary(va_list);
int print_rot(va_list);
int print_unsigned(va_list);
int print_octal(va_list);
int print_hexadecimal_low(va_list);
int print_hexadecimal_upp(va_list);
int print_pointer(va_list);
int print_rev_string(va_list);
int print_non_printable(va_list);

/**
 * struct _format - format structure
 * @type: Format type
 * @f: Associated function
 */
typedef struct _format
{
	char type;
	int (*f)(va_list);
} format;


#endif /** MAIN_H **/
