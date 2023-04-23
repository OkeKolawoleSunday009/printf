#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
typedef struct defSpecs
{
        char identifier;
        int (*print)(va_list args);
} print_t;


int _printf(const char *format, ...);
int print_percent(va_list args);
int print_string(va_list args);
int print_char(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int print_u(va_list args);
int get_func(char c, va_list args);
int print_uint(va_list args);
int print_hex_lower(va_list args);
int *print_octa(va_list args);
int print_hex_higher(va_list args);
int print_binary(va_list args);
int _putchar(char c);
#endif
