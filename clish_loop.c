#include "clish.h"

/**
 * clish_loop - a function that runs the clish shell terminal in a loop,
 * continuously prompting the user for input and processing their commands
 *
 * Return: a void type
 */

int clish_loop(char *argv)
{
	int stat = 1, flag = 0;

	while (stat)
	{
		flag = flag + 1;

		if (isatty(0))
		{
			printf("clish$ ");
		}
		
		stat = line_reader(argv, flag);
	}

	return (0);
}
