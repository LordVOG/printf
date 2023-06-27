#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <starg.h>
#include <stddef.h>
#include <math.h>

/**
  * struct fmt_type - structure rep the format types
  * @fmt_spec: format specifier for each format symbol
  * @func_spec: function pointer that print a data type
  * corresponding to the fmt_spec symbol
  */
typedef struct fmt_type
{
	char fmt_spec;
	int (*func_spf)(va_list arg_param);
} f_type;

/** Fucntion prototypes **/
int _printf(const char *format, ...);

/** Format Specifier function prototypes **/
int p_char(va_list arg_param);

int p_str(va_list arg_param);

int p_int(va_list arg_param);

#endif
