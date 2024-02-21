#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: A pointer to the number.
 * @index: The index, starting from 0, of the bit you want to set.
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index > (sizeof(unsigned long int) * 8 - 1))
        return (-1); /* Check if the index is out of range */

    *n &= ~(1UL << index); /* Clear the bit at position `index` */
    return (1);
}

