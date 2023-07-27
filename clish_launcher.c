#include "clish.h"

/**
 * clish_launcher - the process/ command launcher
 * This function confirms the validity of the command entered by the user as
 * a builtin command, to initiate the appropriate builtin function,
 * For an invalid command, the system call execvp(args) is initiated as
 * an alternate execute method
 * @args: argument count
 *
 * Return: the system call execvp() executor
 */
int (*inbuilt_funct[])(char **) = {&clish_cd, &clish_help, &clish_history, &clish_exit, &clish_grep, &arg_len};

char *inbuilt_str[] = { "help", "exit", "history", "grep", "cd", "sizeof" };

/**
 * inbuilt_cnt - function that returns the size of an inbuilt array
 *
 * Return: an integer type
 */

int inbuilt_cnt()
{
	return (sizeof(inbuilt_str) / sizeof(char *));
}

int clish_launcher(char **args)
{
	int a = 0;

	if (args[0] == NULL)
	{
		return (1);
	}

	else if (strcmp(args[0], "history") != 0 && strcmp(args[0], "exit") != 0 && strcmp(args[0], "clear") != 0)
	{
		input_param(args, " ");
	}
	/* else if	(strcmp(args[0], "exit") != 0)
	{
		input_param(args, " ");
	}
	else if (strcmp(args[0], "cls") != 0)
	{
		input_param(args, " ");
	} */

	for (a = 0; a < inbuilt_cnt(); a++)
	{
		if (strcmp(args[0], inbuilt_str[a]) == 0)
		{
			return ((*inbuilt_funct[a])(args));
		}
	}

	return (clish_execute(args));
}
