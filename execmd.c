#include "main.h"

/**
 * _execmd - executing the command
 * @tok_arr: Users input broken onto strings
 */

void _execmd(char **tok_arr)
{
	char *cmd = NULL;

	if (tok_arr)
	{
		/* getting the first index as the command */
		cmd = tok_arr[0];

		/* get the path the command */
		get_path(cmd);

		if (execve(cmd, tok_arr, NULL) == -1)
			perror("Error:");
	}
}
