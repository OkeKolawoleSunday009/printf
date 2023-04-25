#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int  print_char(va_list args)
{
        int letter;

        letter = va_arg(args, int);
	_putchar(letter);
	return (1);
}

int  print_string(va_list args)
{
        int i, count;
        char *str;

        count = 0;


        str = va_arg(args, char * );

        if (str == NULL)
                str = "(null)";
        count = 0;
        i = 0;
        while (str[i] != '\0')
        {
                _putchar(str[i]);
                i++;
                count++;
        }
        return (count);
}
int print_percent(va_list args)
{
        char *str;

        str = "%";
        if (va_arg(args, int) == *str)
        {
                return (*str);
        }
        _putchar(*str);
	return (1);
}

int print_d(va_list args)
{
        unsigned int absolute, aux, countnum, count;
        int n;

        count = 0;
        n = va_arg(args, int);
        if (n < 0)
        {
                        absolute = (n * -1);
                        count += _putchar('-');
         }
         else
                        absolute = n;

        aux = absolute;
        countnum = 1;
        while (aux > 9)
        {
                aux /= 10;
                countnum *= 10;
        }
        while (countnum >= 1)
        {
                count += _putchar(((absolute / countnum) % 10) + '0');
                countnum /= 10;
        }
        return (count);
}
/**
 * print_i - prints integer
 * @args: integer argument
 * Return: the decimal function
 */

int print_i(va_list args)
{
        return (print_d(args));
}

