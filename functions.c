#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int  print_char(va_list args)
{
        int letter;

        letter = va_arg(args, int);
        return (_putchar(letter));
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
        return (_putchar(*str));
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

int print_binary(va_list args)
{
        unsigned int n, m, i, sum;
        unsigned int a[32];
        int count = 0;

        n = va_arg(args, unsigned int);

        m = 2147483648;
        a[0] = n/m;

        for (i = 1; i < 32; i++)
        {
                m /= 2;
                a[i] = (n / m) % 2;
        }
        for (i = 0, sum = 0; i < 32; i++)
        {
                sum += a[i];
               if (sum || i == 31)
               {
                       char z = '0' + a[i];

                       _putchar(z);
                       count++;
               }
        }
        return (count);


}
int print_u(va_list args) {
    unsigned int n = va_arg(args, unsigned int);
    unsigned int m = 1000000000;
    unsigned int a[10];
    int i, count = 0;

    for (i = 0; i < 10; i++) {
        a[i] = n / m;
        n %= m;
        m /= 10;
    }

    for (i = 0; i < 10; i++) {
        if (a[i] != 0 || i == 9) {
            char c = '0' + a[i];
            _putchar(c);
            count++;
        }
    }

    return count;
}
int print_hex_lower(va_list args)
{
	int count;
	static char buffer[8];
	char *ptr = &buffer[7];
	static char  hex_chars[] = "0123456789abcdef";
	unsigned int n = va_arg(args, unsigned int);
	
	*ptr = '\0';
	count = 0;
	
	do{
		*--ptr = hex_chars[n % 16];
		n /= 16;
	} while (n != 0);
	while (*ptr != '\0')
	{
		_putchar(*ptr);
		count++;
		ptr++;
	}
	return count;
}

int print_hex_higher(va_list args)
{
        int count;
	static char buffer[8];
	char *ptr = &buffer[7];
        static char  hex_chars[] = "0123456789ABCDEF";
        unsigned int n = va_arg(args, unsigned int);

        *ptr = '\0';
        count = 0;

        do{
                *--ptr = hex_chars[n % 16];
                n /= 16;
        } while (n != 0);
        while (*ptr != '\0')
        {
                _putchar(*ptr);
                count++;
                ptr++;
        }
        return count;
}
