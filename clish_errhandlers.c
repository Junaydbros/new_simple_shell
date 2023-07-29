#include "clish.h"

/**
 * ctrl_handle - the function handles the Ctrl-C such that the clish terminal
 * is not exited until prompted by the user with the exit command
 * @args: unused attribute
 *
 * Return: a void type
 */

void ctrl_handle(__attribute__((unused))int args)
{
	signal(SIGINT, ctrl_handle);
	getchar();
}

/**
 * cli_handler - a function that handles command line arguments
 * @args: user command
 *
 * Return: an integer type
 */

int cli_handler(char *line, char **args)
{
	char *token, *argv, *csh;
	int a = 0;

	argv = line;

	csh = csh_strtok(line, "\n\t\r ");

	args[a] = csh;

	do {
		a++;
		token = csh_strtok(NULL, "\n\t\r");
		argv = token;
		args[a] = token;
	} while (argv != NULL);
	args[a] = NULL;

	return (a);
}
/**
 * err_handler - a function that handles error inputs
 * @arg: the error message to be printed
 *
 * Return: a void type
 */

void err_handler(char *arg, int exit_param)
{
	perror(arg);

	if (exit_param == 0)
	{
		return;
	}

	exit(exit_param);
}
/**
 * errmsg_handler - a function that handles error message output to terminal
 * @argv: an argument
 *
 * Return: an integer type
 */

int errmsg_handler(char *argv, int cnt, char *csh, char *args)
{
	char *args_buff;
	int w_cnt;

	char *numb_str = atioa(cnt);
	int argv_cnt = csh_strlen(argv);
	int csh_cnt = csh_strlen(csh);
	int args_cnt = csh_strlen(args);
	int numb_cnt = csh_strlen(numb_str);
	int total_cnt = argv_cnt + csh_cnt + args_cnt + numb_cnt;

	args_buff = malloc(sizeof(char *) * total_cnt + 5);
	if (args_buff == NULL)
	{
		err_handler("Error handling", 0);
	}
	strcat(args_buff, argv);
	strcat(args_buff, ":");
	strcat(args_buff, " ");
	strcat(args_buff, numb_str);
	strcat(args_buff, ":");
	strcat(args_buff, " ");
	strcat(args_buff, csh);
	strcat(args_buff, ":");
	strcat(args_buff, args);

	w_cnt = write(STDERR_FILENO, args_buff, (total_cnt + 5));

	free(numb_str);
	free(args_buff);

	return (w_cnt);
}

/**
 * atioa - a function that converts an integer to string
 * @ch: a character variable
 *
 * Return: a character type
 */

char *atioa(int numb)
{
	int a, cnt = 0;
	int mode, temp;
	char *ch;

	temp = numb;

	while (temp != 0)
	{
		cnt++;
		temp /= 10;
	}

	ch = malloc(sizeof(char) * (cnt + 1));

	for (a = cnt - 1; a >= 0; a--)
	{
		mode = numb % 10;
		ch[a] = mode + '0';
		numb /= 10;
	}
	ch[cnt] = '\0';

	return (ch);
}
