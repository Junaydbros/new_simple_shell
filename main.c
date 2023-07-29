#include "clish.h"

/**
 * main - the program runs the clish shell terminal
 * @argc: an argument count
 * @argv: an argument vector
 *
 * Return: an integer type
 */

int main(__attribute__((unused))int argc, char **argv)
{
	clish_loop(argv[0]);

	return (EXIT_SUCCESS);
}
