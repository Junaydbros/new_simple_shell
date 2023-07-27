#include "clish.h"

/**
 * clish_loop - a function that runs the clish shell terminal in a loop,
 * continuously prompting the user for input and processing their commands
 *
 * Return: a void type
 */

void clish_loop(void)
{
	char *line;
	char **args;
	int stat = 1, a = 0, flag = 0;

	while (stat)
	{
		get_dir("loop");
		printf("$ ");
		line = line_reader();
		flag = 0;
		a = 0;

		while (line[a] != '\0')
		{
			if (line[a] == '|')
			{
			flag = 1;
			break;
			}
			a++;
		}

		if (flag)
		{
			pipe_input_param(line);
			args = pipe_split(line);
			stat = clish_pipe(args);
		}
		else
		{
			args = line_split(line);
			stat = clish_launcher(args);
		}

		free(line);
		free(args);
	}
}
