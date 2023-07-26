#include "clish.h"
/**
 * clish_execute - the function executes the system call execvp taking the
 * tokenized user input as argument.
 * This execvp() call takes place in the child process and the parent has to
 * wait until the child process terminates
 * @args: the argument cont
 *
 * Return: 1 on success
 */

int clish_execute(char **args)
{
	pid_t pid;
	int stat;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) < 0)
		{
			printf("clish: Unidentified command: %s\n", args[0]);
		}

		exit(EXIT_FAILURE);
	}

	else if (pid < 0)
	{
		printf("Fork Error\n");
	}

	else
	{
		waitpid(pid, &stat, WUNTRACED);
	}

	return (1);
}
