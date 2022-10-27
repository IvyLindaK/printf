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
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				counter++;
				i = i + 2;
				continue;
			}
			else
			{
				fp = format_check(&format[i + 1]);
				if (fp == NULL)
					return (-1);
				i = i + 2;
				counter = counter + fp(args);
				continue;
			}
		}
		i++;
	}
	va_end(args);
	return (counter);
}
