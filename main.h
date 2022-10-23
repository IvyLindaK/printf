#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct special_characters - Structure containing special structures
 * and their functions
 * @s: the special function
 * @f: function pointer
 */
typedef struct special_characters
{
	char *s;
	int (*f)(va_list);
} spec;/* specifiers */

int _printf(const char *format, ...);
int _putchar(char c);
int (*check_format(const char *format))(va_list);
int (*format_check(const char *format))(va_list);
int print_char(va_list arg_c);
int print_str(va_list arg_str);


#endif
