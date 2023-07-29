#include "clish.h"

/**
 * arg_len - function for argument length
 * @args: argument string
 *
 * Return: an integer type
 */

int arg_len(char **args)
{
	int b = 0;

	while (args[b] != NULL)
	{
		b++;
	}

	return (b);
}

/**
 * whitespace_trim - this function helps to eliminate trailing whitespace
 * @str: a string
 *
 * Return: a string type

char *whitespace_trim(char *str)
{
	char *end;

	while (isspace((unsigned char) *str))
	{
		str++;
	}

	if (*str == 0)
	{
		return (str);
	}
	end = str + strlen(str) - 1;

	while (end > str && isspace((unsigned char) *end))
	{
		str--;
	}

	*(end + 1) = 0;

	return (str);
} */
