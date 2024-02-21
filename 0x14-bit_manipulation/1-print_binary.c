#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to be printed in binary
 */
void print_binary(unsigned long int n)
{
    if (n > 1) /* If n is greater than 1, there's more than one bit to print */
        print_binary(n >> 1); /* Recursively call print_binary with n shifted right by 1 bit */

    _putchar((n & 1) + '0'); /* Print the least significant bit of the current number */
}

