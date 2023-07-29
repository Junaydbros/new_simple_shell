#include "clish.h"


/**
 * clish_environ - a function that sets clish SHELL environment
 * using linked list style
 *
 * @str: environment string
 *
 * Return: pointer to list head
 */

env_list *clish_environ(char **str)
{
	env_list *lead;

	if (!str || !str[0])
		return (NULL);

	/*memory allocation for the head node*/
	lead = malloc(sizeof(env_list));
	if (!lead)
	{
		perror("failed memory allocation");
		exit(EXIT_FAILURE);
	}

	lead->envistr = csh_strdup(str[0]);
	lead->nnode = clish_environ(str + 1);

	return (lead);
}


/**
 * set_clish_envarray - a function that sets environment string array
 *
 * @str: environment string
 *
 * Return: a chgaracter type
 */

char **set_clish_envarray(char **str)
{
	char **arr_env = NULL;
	int a;

	if (str == NULL)
		return (NULL);
	for (a = 0; str[a]; a++)
		;

	arr_env = malloc(sizeof(char *) * (a + 1));
	for (a = 0; str[a]; a++)
	{
		arr_env[a] = csh_strdup(str[a]);
	}
	arr_env[a] = NULL;

	return (arr_env);
}

/**
 * getstrpath - a function that returns a pointer to environment string
 *
 * @name: environment variable name
 *
 * Return: a character type
 */

char *getstrpath(const char *name)
{
	char *strpath;
	size_t c, s;
	int flag = 0;

	size_t len = csh_strlen(name);

	for (c = 0; environ[c]; c++)
	{
		strpath = environ[c];

		for (s = 0; s < len; s++)
		{
			if (strpath[0] == name[0])
				flag = 1;
			if (strpath[s] == name[s])
				continue;
			break;
		}

		if (strpath[s] == '=' && flag == 1)
			return (strpath);
	}

	return (NULL);
}
