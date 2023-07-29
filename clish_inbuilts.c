#include "clish.h"

/**
 * clish_cd - a function that changes the current directory in the clish shell
 * terminal
 * @args: argument string
 *
 * Return: an integer type
 */

int clish_cd(char **args)
{
	char *lineptr, c_linptr;
	char **clish;
	
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

int clish_exit(char **args)
{
	char *lineptr, *c_lineptr;
	char **clish;

	freeLAP(args, clish, lineptr, c_lineptr, NULL);

	if (errno != 0)
	{
		exit (errno);
	}

	exit (0);
}

/**
 * clish_help - a function that displays help on the clish terminal interface
 * @args: an argument string
 *
 * Return: an integer type
 */

int clish_help(char **args)
{
	if (args[0] != NULL && strcmp(args[0], "help") == 0)
	{
		fprintf(stderr, "\n------------\n"
				"\nclish is a simple UNIX terminal shell written with C language,\n"
				"\nThis project was developed as an evaluation project in the ALX Software Engineering Programme to test student's understanding of C programming language\n"
				"\nProject was done as a team of two and the authors of this project are Abdlhamid Sanusi and Kamma Okoh\n"
				"\nA Very challenging task but Kudos to the brains behind this masterpiece\n"
				"\n The currently supported commands include:\n1. cd\n2. cat \n3. touch \n4. help \n5. exit"
				"\n------------\n");
	}

	return (1);
}

int clish_path(char **args)
{
	char *lineptr, *c_lineptr;
	char **clish;
	size_t a = 0;

	do {
		_puts(environ[a]);
		_puts("\n");
		a++;
	} while (environ[a])

	freeLAP(args, clish, lineptr, c_lineptr, NULL);

	return (1);
}

/* Note that this file handles all the inbuilt implementation commands of... */
/* the SHELL terminal */
