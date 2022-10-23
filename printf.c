#include "main.h"

int  _printf(const char *format, ...)
{
	va_list ap;
	int i, j = 0, len;
	char *buffer;

	while (format)
	{
		for (i = 0; format[i] != '\0'; i++)
			len++;
	}

	va_start(ap, format);
	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
		return(NULL);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c':
					buffer[j] = (char)va_arg(ap, int);
					j++;
					break;
				case 's':
					buffer[j] = (char)va_arg(ap, int);
					j++;
					break;
			}
		}
		else
			buffer[j] = format[i];

}
