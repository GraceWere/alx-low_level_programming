#include "main.h"

/**
 * This code helps to convert a binary string to an unsigned integer
 * It checks if the binary string is valid and contains only 0s and 1s
 * If the string is valid, it converts the binary string to an unsigned integer
 * If the string is invalid, it returns 0
*/

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[i] - '0');
	}

	return (dec_val);
}
