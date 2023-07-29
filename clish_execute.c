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

int clish_execute(char **args, char *lineptr, char *argv, int exe_cnt, char **clish, char *c_lineptr)
{
	int a, inbuilt_cnt;

	char *inbulit_str[] = {"exit", "cd", "path", "help" };

	int (*inbuilt_funct[])(char **, char *, char **, char *, char **) = {
		&clish_exit, &clish_cd, &clish_path, &clish_help };

	inbuilt_cnt = sizeof(inbuilt_str) / sizeof(char *);

	for (a = 0; a < inbuilt_cnt; a++)
	{
		if ((csh_strcmp(args[0], inbuilt_str[a]) == 0))
		{
			return ((*inbuilt_funct[a])(args, lineptr, clish, c_lineptr));
		}
	}

	return (clish_otherexec(args, lineptr, argv, exe_cnt, clish, c_lineptr));
}

/**
 * clish_otherexec - the function helps the clish SHELL execute other commands
 * @args: user command
 *
 * Return: an integer type
 */

int clish_otherexec(char **args, char *lineptr, char *argv, int exe_cnt, char **clish, char *c_lineptr)
{
	char *path, *comm;
	int stat, flag = 0;
	pid_t pid;
	size_t cnt;

	comm = args[0];
	for (cnt = 0; comm[cnt]; cnt++)
	{
		if (comm[cnt] == '/')
		{
			flag = 1;
			path = comm;
			break;
		}
	}
	if (flag != 1)
		path = set_param_path(args);
	if (path == NULL)
	{
		errmsg_handler(argv, exe_cnt, args[0], " input not found\n");
		freeLAP(args, clish, lineptr, path, c_lineptr);
		exit(127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			freeLAP(args, clish, lineptr, path, c_lineptr);
			err_handler("Input execution unsuccessful", EXIT_FAILURE);
		}
	}
	else
		wait(&stat);
	freeLAP(args, clish, lineptr, c_lineptr, NULL);
	if (flag != 1)
		free(path);
	return (1);
}

/**
 * freeLAP - a function that free buffer linepointers and paths
 * @args: an argument
 *
 * Return: a void type
 */

void freeLAP(char **args, char **clish, char *lineptr, char *path, char *c_lineptr)
{

	if (args != NULL)
	{
		free(args);
	}

	if (clish != NULL)
	{
		free(clish);
	}

	if (lineptr != NULL)
	{
		free(lineptr);
	}

	if (path != NULL)
	{
		free(path);
	}

	if (c_lineptr != NULL)
	{
		free(c_lineptr);
	}
}
