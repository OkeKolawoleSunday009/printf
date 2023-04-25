#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
int print_binary(va_list args)
{
        unsigned int n, i, sum;
        unsigned int a[32];
        int count;
	unsigned int z;

	z = 2147483647;
	count = 0;

        n = va_arg(args, unsigned int);
        a[0] = n/z;

        for (i = 1; i < 32; i++)
        {
                z /= 2;
                a[i] = (n / z) % 2;
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
        static char buffer[1024];
        char *ptr = &buffer[1023];
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
	static char buffer[1024];
        char *ptr = &buffer[1023];
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
int print_octa(va_list args)
{
        int count;
        static char buffer[1024];
        char *ptr = &buffer[1023];
        static char  chars[] = "0123456789ABCDEF";
        unsigned int n = va_arg(args, unsigned int);

        *ptr = '\0';
        count = 0;

        do{
                *--ptr = chars[n % 8];
                n /= 8;
        } while (n != 0);
        while (*ptr != '\0')
        {
                _putchar(*ptr);
                count++;
                ptr++;
        }
        return count;
}
int print_py(va_list args)
{
	char buffer[1024];
	int i, count;
	void* ptr  = va_arg(args, void*);

	count = 0;
	sprintf(buffer, "%p", ptr);
        for (i = 0; buffer[i] != '\0'; i++)
	{
               _putchar(buffer[i]);
		count++;
        }
	return (count);
        
}
void print_non_printable(char c) {
    unsigned char uc = (unsigned char) c;
    _putchar('\\');
    _putchar('x');
    _putchar((uc >> 4) + ((uc >> 4) < 10 ? '0' : 'A' - 10));
    _putchar((uc & 0xF) + ((uc & 0xF) < 10 ? '0' : 'A' - 10));
}
int print_special(va_list args)
{
	char* s = va_arg(args, char*);
       	while (*s != '\0') 
	{
		if (*s < 32 || *s >= 127)
			print_non_printable(*s);
		else
			_putchar(*s);
       		 s++;
        }
	return (1);
}
