#include "main.h"

/**
 * set_bit - sets a bit at a specified index to 1
 * @n: pointer to the number to be modified
 * @index: index of the bit to set to 1
 *
 * Return: 1 on success, -1 on failure
 *
 * Description: This function sets a bit at a given index to the value of 1 in
 * the specified number. It takes a pointer to the number
 * that needs to be changed
 * and the index of the bit that should be set as parameters. If the index is
 * greater than 63, the function returns -1
 * to indicate failure; otherwise, it sets
 * the bit at the specified index and returns 1 to indicate success.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
