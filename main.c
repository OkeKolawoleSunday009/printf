#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main() {
    int a = 10;
    long b = 100;
    short c = 5;

    my_printf("a = %d\n", a);        // prints: a = 10
    my_printf("b = %ld\n", b);       // prints: b = 100
    my_printf("c = %hd\n", c);       // prints: c = 5

    return 0;
}
