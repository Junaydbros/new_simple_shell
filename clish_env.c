#include "clish.h"


/**
 * set_clish_env - function that sets new environment for clish
 *
 * @name: environment name
 * @val: environment value
 * @owrite: overwrite environment value if set to a nonzero value
 *
 * Return: an intger type
 */

int set_clish_env(const char *name, const char *val, int owrite)
{
	char **arr_env;
	int a, env_place = 0;
	char *env_str;

	arr_env = malloc(sizeof(char **));
	if (arr_env == NULL)
	{
		perror("environment setup failed");
		return (-1);
	}
	env_str = get_clish_envstr(name);
	/*copy environment to new variable*/
	for (a = 0; environ[a]; a++)
	{
		env_arr[a] = my_strdup(environ[a]);
	}

	if (env_str == NULL)
	{
		env_arr[a] = set_env_str(name, val);
		env_arr[a + 1] = NULL;
	}
	else if (owrite != 0)
	{
		env_arr[a] = NULL;
		for (a = 0; environ[a]; a++)
		{
			if (csh_strcmp(environ[a], env_str) == 0)
				env_place = a;
		}
		arr_env[env_place] = clish_env_str(name, val);
	}

	environ = arr_env;

	return (0);
}

/**
 * clish_env_str - handles environment string for the clish SHELL
 *
 * @name: environment variable
 * @val: environment value
 *
 * Return: a cahracter type
 */

char *clish_env_str(const char *name, const char *val)
{
	int n_len, v_len, t_len;
	char *str;

	n_len = csh_strlen(name);
	v_len = csh_strlen(val);
	t_len = n_len + v_len;

	str = malloc(sizeof(char) * t_len + 1);
	if (str == NULL)
		err_handler("setenv malloc error", EXIT_FAILURE);

	str[0] = '\0';
	csh_strcat(str, name);
	csh_strcat(str, "=");
	csh_strcat(str, val);

	return (str);
}
