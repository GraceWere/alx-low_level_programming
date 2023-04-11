#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 *
 * Return: 0 for big endian, 1 for little endian
 *
 * Description: This function determines whether the machine it is running on
 * is big endian or little endian. It does so by creating a 4-byte unsigned
 * integer with a value of 1, and then checking the value of the first byte.
 * If the first byte is 1, then the machine is little endian; otherwise, it is
 * big endian.
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
