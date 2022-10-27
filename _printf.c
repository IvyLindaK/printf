#include "main.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - Function that implements printf
 * @format: string to print
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int (*fp)(va_list);
	int counter = 0, i = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			fp = format_check(&format[i]);
			counter = counter + fp(args);
			continue;
		}
		else
		{
			_putchar(format[i]);
			counter++;
		}
		i++;
	}
	va_end(args);
	counter = counter - 1;
	return (counter);
}
