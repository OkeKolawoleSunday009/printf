#include "main.h"


/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */


int get_func(char c, va_list args)
{
	int i;

	print_t cspec[] = {
		 {'c', print_char},
		 {'s', print_string},
		 {'%', print_percent},
		 {'d', print_d},
		 {'i', print_i},
		 {'o', print_octa},
		 {'b', print_binary},
		 {'x', print_hex_lower},
		 {'u', print_u},
		 {'X', print_hex_higher},
		 {'p', print_py},
		 {'S', print_special}
	};
	i = 0;
	while (cspec[i].identifier)
	{
		if (cspec[i].identifier == c)
			return (cspec[i].print(args));
        i++;
	}
	
	return (_putchar(c));
}


