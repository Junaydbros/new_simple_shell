#include "main.h"

/**
 * get_path - getting the path of the command
 * @cmd: the command passed
 * Return: the command.
 */

char *get_path(char *cmd)
{
	char *p, *p_cpy, *p_tok, *p_file;
	int cmd_len, dir_len;
	char *delim = ":";
	struct stat buffer;

	p = getenv("PATH");

	if (p)
	{
		p_cpy = strdup(p);
		cmd_len = strlen(cmd);

		p_tok = strtok(p_cpy, delim);

		while (p_tok != NULL)
		{
			dir_len = strlen(p_tok);
			p_file = malloc(cmd_len + dir_len + 2);
			strcpy(p_file, p_tok);
			strcat(p_file, "/");
			strcat(p_file, cmd);
			strcat(p_file, "\0");

			if (stat(p_file, &buffer) == 0)
			{
				free(p_cpy);
				return (p_file);
			}
			else
			{
				free(p_file);
				p_tok = strtok(NULL, delim);
			}
		}
		free(p_cpy);
		if (stat(cmd, &buffer) == 0)
			return (cmd);
		return ("");
	}
	return ("");
}
