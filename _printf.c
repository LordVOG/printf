#include "main.h"

/**
  * _printf - function that produce output according to a format string
  * @format: format string
  *
  * Return: format output
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int i;

