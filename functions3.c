#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void handle_long_and_short(char** format, ...)
{
	while (1)
	{
		if (*format == 'l') {
                format++;
                if (*format == 'd') {
                    long value = va_arg(args, long);
                    print_d(value);
                }
                else if (*format == 'i'){
                    long value = va_arg(args, long);
                    print_d(value);

                } else if (*format == 'u') {
                    unsigned long value = va_arg(args, unsigned long);
                    printf("%lu", value);
                } else if (*format == 'o') {
                    unsigned long value = va_arg(args, unsigned long);
                    printf("%lo", value);
                } else if (*format == 'x' || *format == 'X'){
                    unsigned long value = va_arg(args, unsigned long);
                    if (*format == 'x') {
                        print_hex_lower(value);
                    } else {
                        print_hex_higher("%lX", value);
                    }
                }
            }
		(*format++);
	}

}
