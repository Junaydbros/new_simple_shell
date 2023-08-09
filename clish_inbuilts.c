#include "clish.h"


/**
 * clish_cd - a function that changes the current directory in the clish shell
 * terminal
 * @args: argument string
 *
 * Return: an integer type
 */

int clish_cd(char **args, char *lineptr, char **clish, char *c_lineptr)
{

	if (args[1] == NULL)
	{
		fprintf(stderr, "clish: Enter a directory path\n");
	}

	else
	{
		if (chdir(args[1]) > 0)
		{
			perror("clish error\n");
		}
	}

	freeLAP(args, clish, lineptr, c_lineptr, NULL);

	return (1);
}

/**
 * clish_exit - a function that exits the clish shell terminal interface
 * @args: an argument string
 *
 * Return: an integer type
 */

int clish_exit(char **args, char *lineptr, char **clish, char *c_lineptr)
{

	freeLAP(args, clish, lineptr, c_lineptr, NULL);

	if (errno != 0)
	{
		exit(errno);
	}

	exit(0);
}

/**
 * clish_help - a function that displays help on the clish terminal interface
 * @args: an argument string
 *
 * Return: an integer type
 */

int clish_help(char **args, char *lineptr, char **clish, char *c_lineptr)
{
	if (args[0] != NULL && strcmp(args[0], "help") == 0)
	{
		fprintf(stderr, "\n------------\n");
		fprintf(stderr, "\nclish is a simple UNIX terminal shell written with");
		fprintf(stderr, " C language,\n");
		fprintf(stderr,	"\nThis project was developed as an evaluation project in ");
		fprintf(stderr, "the ALX Software Engineering Programme to test student's");
		fprintf(stderr, " understanding of C programming language\n");
		fprintf(stderr,	"\nProject was done as a team of two and the authors of ");
		fprintf(stderr, "this project are Abdlhamid Sanusi and Kamma Okoh\n");
		fprintf(stderr,	"\nA Very challenging task but Kudos to the brains behind ");
		fprintf(stderr, "this masterpiece\n");
		fprintf(stderr,	"\n The currently supported commands include:\n1. cd\n2. ");
		fprintf(stderr, "cat \n3. touch \n4. help \n5. exit");
		fprintf(stderr,	"\n------------\n");
	}
	freeLAP(args, clish, lineptr, c_lineptr, NULL);

	return (1);
}

/**
 * clish_path - a function that prints environment variables
 * @args: user command
 *
 * Return: an intger type
 */

int clish_path(char **args, char *lineptr, char **clish, char *c_lineptr)
{
	size_t a = 0;

	do {
		_puts(environ[a]);
		_puts("\n");
		a++;
	} while (environ[a]);

	freeLAP(args, clish, lineptr, c_lineptr, NULL);

	return (1);
}

/* Note that this file handles all the inbuilt implementation commands of... */
/* the SHELL terminal */
