#ifndef FUNCTION_H
#define FUNCTION_H

#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a character
 * @arg_c: character arguement
 *
 * Return: 1 for success
 */

int print_char(va_list arg_c)
{
	/*char *buff;*/
	int x;

	x = va_arg(arg_c, int);
	_putchar(x);
	return (1);
}

/**
 * print_str - prints string
 * @arg_str: string arguement
 *
 * Return: 1 Always success
 */

int print_str(va_list arg_str)
{
	char *str_arg = va_arg(arg_str, char*);
	int x = 0;

	while (str_arg[x] != '\0')
	{
		_putchar(str_arg[x++]);
	}
	return (1);
}

/**
 * print_percent - prints the % sign
 * @arg: arguements
 *
 * Return: Number of characters printed
 */
/*int print_perc(__unused__((unused))va_list arg)
{
	_putchar('%');
	return (1);
}*/

/**
 * format_check - checks the format specifiers
 * @format: specifier
 *
 * Return: relevant function
 */
int (*format_check(const char *format))(va_list)
{
	int i = 0;

	spec sp[] = {
		{"c", print_char},
		{"s", print_str},
		/*{"%", print_perc},
		{"d", print_dec},
		{"i", print_int},*/
		{NULL, NULL}
	};

	for (; sp[i].s != NULL; i++)
	{
		if (*(sp[i].s) == *format)
			break;
	}
	return (sp[i].f);
}

/**
 * print_dec - prints decimal number
 * @arg_dec: string arguement
 *
 * Return: 1 always succes
 */

/**
 * _putchar - prints out character
 * @c: character input
 *
 * Return: 0
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#endif
