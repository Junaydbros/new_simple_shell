#include "clish.h"

/**
 * pipe_input_param - function that pipes input for the history command
 * @line: line to be piped
 *
 * Return: a void type

void pipe_input_param(char *line)
{
	FILE *input_file = fopen(get_input_param_path(), "a+");

	fprintf(input_file, "%d. %s\n", input_param_count(), line);
	fclose(input_file);
} */

/**
 * set_param_path - function that fetches input for the history command
 * @args: argument string
 * @d: a character
 *
 * Return: a void type
 */

char *set_param_path(char **args)
{
	char *pathh, *c_path, *c_pathh;
	char *token;
	char **arr_path;
	size_t cnt = 0;

	char *clish = args[0];
	pathh = clish_path("PATH");

	c_path = csh_strdup(pathh);
	c_pathh = csh_strdup(pathh);

	if (c_path == NULL)
	{
		err_handler("Duplication of paths fell through\n", EXIT_FAILURE);
	}
		token = csh_strtok(c_path, ":");
		while (token)
		{
			cnt++;
			token = csh_strtok(NULL, ":");
		}
		free(c_path);
		arr_path = malloc(sizeof(char *) * (cnt + 1));

		if (arr_path == NULL)
		{
			err_handler("Error in memory allocation\n", EXIT_FAILURE);
		}
		token = csh_strtok(c_pathh, ":");
		
		for (cnt = 0; token; cnt++)
		{
			arr_path[cnt] = token;
			token = csh_strtok(NULL, ":");
		}
		arr_path[cnt] = NULL;

		return (get_input_param_path(arr_path, clish, c_pathh));
}

/**
 * get_input_param_path - a function that fetches the file path for the history
 * @clish: user command
 *
 * Return: a character type
 */

char *get_input_param_path(char *clish)
{
	char **arr_path;
	char *pathh;
	char *path, *get_path;

	size_t cnt = 0;
	size_t param_path, clish_len;

	clish_len = csh_strlen(clish);
	
	for (cnt = 0; arr_path[cnt]; cnt++)
	{
		get_path = csh_strdup(arr_path[cnt]);
		param_path = csh_strlen(get_path);
		path = malloc(sizeof(char) * (param_path + clish_len + 2));

		path[0] = '\0';
		csh_strcat(path, get_path);
		csh_strcat(path, "/");
		csh_strcat(path, clish);

		if (access(path, X_OK) == 0)
		{
			free(get_path);
			free(arr_path);
			free(pathh);

			return (path);
		}
		free(get_path);
		free(path);
	}
	free(arr_path);
	free(pathh)

	return (NULL);
}

/**
 * input_param_count - a function that returns the count of the history command
 *
 * Return: an integer type

int input_param_count()
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
} */

/* Note that this files handles parameters that work to execute commands */
