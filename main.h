#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

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
int print_octa(va_list args);
int print_hex_higher(va_list args);
int print_binary(va_list args);
int _putchar(char c);
int print_py(va_list args);
int print_special(va_list args);
void handle_flags(char** format, int* flag_plus, int* flag_space, int* flag_hash);
void my_printf(const char* format, ...);
void handle_long_and_short(char** format, ...);
#endif
