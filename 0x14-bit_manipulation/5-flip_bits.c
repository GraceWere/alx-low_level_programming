#include "main.h"

/**
 * flip_bits - Returns the number of bits you would need to flip
 * to get from one number to another.
 * @n: The first number.
 * @m: The second number, to compare with the first.
 * Return: The number of bits needed to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int xor = n ^ m; /* Find differing bits */
    unsigned int count = 0;

    while (xor) /* Count the number of set bits */
    {
        count += xor & 1; /* Increment count if the LSB is set */
        xor >>= 1; /* Shift right by 1 bit to check the next bit */
    }

    return count;
}

