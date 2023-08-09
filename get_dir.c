#include "clish.h"


/**
 * get_dir - a function that fetches the current working directory for the
 * prompt
 * @form: the state of the cwd
 *
 * Return: a void type
 */

void get_dir(char *form)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (strcmp(form, "loop") == 0)
		{
			printf("[       %s      ]\n", cwd);
		}
		else if (strcmp(form, "pwd") == 0)
		{
			printf("%s\n", cwd);
		}
	}

	else
	{
		printf("Error processing getcwd()\n");
	}
}
