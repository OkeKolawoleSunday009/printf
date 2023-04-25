
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>

int _printf(const char *format, ...)
{
	va_list a;
	int i, count;
	

	if (format == NULL)
		return (0);

	count = 0;
	va_start(a, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			count += get_func(format[i + 1], a);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			count += _putchar(format[i] + format[i]);
		}
		else
			count += _putchar(format[i]);
	}
	return (count);
}

