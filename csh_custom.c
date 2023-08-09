#include "clish.h"


/**
 * _putchar - a function that prints a character
 * @c: the character to be printed
 *
 * Return: an integer type
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - a function that prints a string
 * @str: the string to be printed
 *
 * Return: an integer type
 */

int _puts(char *str)
{
	int c;

	for (c = 0; str[c]; c++)
	{
		_putchar(str[c]);
	}

	return (0);
}
