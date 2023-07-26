#include "clish.h"

/**
 * pipe_input_param - function that pipes input for the history command
 * @line: line to be piped
 *
 * Return: a void type
 */

void pipe_input_param(char *line)
{
	FILE *input_file = fopen(get_input_param_path(), "a+");

	fprintf(input_file, "%d. %s\n", input_param_count(), line);
	fclose(input_file);
}

/**
 * input_param - function that fetches input for the history command
 * @args: argument string
 * @d: a character
 *
 * Return: a void type
 */

void input_param(char **args, char *d)
{
	FILE *input_file = fopen(get_input_param_path(), "a+");

	int m = 0;

	fprintf(input_file, "%d. ", input_param_count());

	while (args[m] != NULL)
	{
		if (m > 0)
		{
			fputs(d, input_file);
		}
		fputs(args[m], input_file);
		m++;
	}
	fputs("\n", input_file);
	fclose(input_file);
}

/**
 * get_input_param_path - a function that fetches the file path for the history
 * command
 *
 * Return: a character type
 */

char *get_input_param_path()
{
	static char param_path[128];

	strcat(strncpy(param_path, getenv("HOME"), 113), "./clish_history");

	return (param_path);
}

/**
 * input_param_count - a function that returns the count of the history command
 *
 * Return: an integer type
 */

int input_param_count(void)
{
	FILE *fp = fopen(get_input_param_path(), "r");
	int c;
	int line_nums = 1;

	while (c != EOF)
	{
		c = getc(fp);
		if (c == '\n')
		{
			line_nums++;
		}
	}

	return (line_nums);
}

/* Note that this files handles parameters that work to execute commands */
