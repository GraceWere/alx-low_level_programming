#include "main.h"

/**
 * flip_bits - counts the number of bits to
 * change to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 *
 * Description: This function calculates
 * the number of bits that need to be flipped
 * in order to convert one number to another.
 * It takes two unsigned long integers as
 * parameters, n and m, which represent the
 * two numbers being compared.The function
 * then calculates the XOR of n and m,
 * which results in a number where each bit represents
 * whether the corresponding bits in n and m
 * are the same (0) or different (1). The function
 * then counts the number of 1's in the XOR result
 * and returns that count as the number of
 * bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
