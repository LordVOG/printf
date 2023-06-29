#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <math.h>
#include <unistd.h>

/**
  * struct fmt_type - structure rep the format types
  * @fsc: format specifier for each format symbol
  * @func: function pointer that print a data type
  * corresponding to the fmt_spec symbol
  */
typedef struct fmt_type
{
	char *fsc;
	int (*func)(va_list);
} f_type;



/** Fucntion prototypes **/
int _printf(const char *format, ...);
int _putchar(char c);



/** Format Specifier function prototypes **/
int print_schar(va_list c);

int print_dec(va_list d);

int print_float(va_list f);

int print_str(va_list s);

int print_int(va_list i);

int print_octal(va_list o);

int print_undec(va_list u);

int print_lwhex(va_list x);

int print_uphex(va_list X);

int print_bin(va_list b);

int print_rev(va_list r);

int print_rot13(va_list R);

#endif
