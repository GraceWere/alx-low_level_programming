#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>

int _putchar(char c);

#endif /* MAIN_H */

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
