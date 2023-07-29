#include "shell.h"
/**
 * clish_getpath - a function that return the environment value of a prompt
 * @var: the environment variable
 *
 * Return: a character type
 */

char *clish_getpath(char *var)
{
	size_t c, s;
	size_t len = csh_strlen(var);
	char *env_str;

	for (c = 0; environ[c]; c++)
	{
		env_str = environ[c];

		for (s = 0; s < len; s++)
		{
			if (env_str[s] == var[s])
			{
				continue;
			}
			break;
		}

		if (s == len && env_str[s] == '=')
		{
			return (csh_strstr(env_str, "="));
		}
	}

	return (NULL);
}
