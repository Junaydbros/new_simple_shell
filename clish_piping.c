#include "clish.h"
/**
 * pipe_split - a function that allows the splitting of piped commands into bit
 * @in: an input
 *
 * Return: a character type
 */

char **pipe_split(char *in)
{
	char *cl = strtok(in, "|");
	char **sh = malloc(1024 * sizeof(char *));
	int li = 0;

	while (cl != NULL)
	{
		sh[li] = whitespace_trim(cl);
		li++;

		cl = strtok(NULL, "|");
	}
	sh[li] = NULL;
	li = 0;

	while (sh[li] != NULL)
	{
		printf("%s\n", sh[li]);
		li++;
	}
	return (sh);
}

/**
 * clish_pipe - function that allows piping of commands in the clish terminal
 * @args: an argument string
 *
 * Return: an integer type
 */

int clish_pipe(char **args)
{
	/* current sttandard input and output saved for restoration */
	int tempoin = dup(0);
	int tempoout = dup(1);
	int c = 0, l = 0, flag = 0;
	int inredir = 0, outredir;

	c = 0;
	while (c < arg_len(args))
	{
		if (strcmp(args[c], "$") == 0)
		{
			inredir = open(args[c + 1], O_RDONLY);
			flag = flag + 2;
		}
		c++;
	}

	if (!inredir)
	{
		inredir = dup(tempoin);
	}

	int pid;

	for (l = 0; l < arg_len(args) - flag; l++)
	{
		char **rargs = line_split(args[l]);

		dup2(inredir, 0);
		close(inredir);

		if (l == arg_len(args) - 3 && strcmp(args[l + 1], "$") == 0)
		{
			if (outredir == open(args[l + 1], O_WRONLY))
			{
				l++;
			}
		}
		else if (l == arg_len(args) - flag - 1)
		{
			outredir = dup(tempoout);
		}
		else
		{
			int redir[2];

			pipe(redir);
			outredir = redir[1];
			inredir = redir[0];
		}

		dup2(outredir, 1);
		close(outredir);

		pid = fork();

		if (pid == 0)
		{
			execvp(rargs[0], rargs);
			perror("Fork error\n");
			exit(EXIT_FAILURE);
		}

		wait(NULL);
	}

	dup2(tempoin, 0);
	dup2(tempoout, 1);
	close(tempoin);
	close(tempoout);

	return (1);
}
