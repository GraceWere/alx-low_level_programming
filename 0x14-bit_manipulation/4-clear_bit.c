#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: pointer to the number to be modified
 * @index: index of the bit to clear
 *
 * Return: 1 on success, -1 on failure
 *
 * Description: This function sets the value of a bit at a specified index to 0
 * in the specified number. It takes a pointer to the number that needs to be changed
 * and the index of the bit that should be cleared as parameters. If the index is
 * greater than 63, the function returns -1 to indicate failure; otherwise, it clears
 * the bit at the specified index and returns 1 to indicate success.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
