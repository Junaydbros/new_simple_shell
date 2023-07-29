#include "shell.h"

/**
 * csh_strtok - a function that tokenizes a string
 * @str: the string to be tokenized
 * @delim: a delimiter
 *
 * Return: a character type
 */

char *csh_strtok(char *str, const char *delim)
{
	static char *n_str;
	char *token;
	int c, s;

	if (!str && delim)
	{
		if (!n_str)
		{
			return (NULL);
		}
		n_str = jump_prev_delim(n_str, delim);
		str = n_str;
	}

	if (str && !n_str)
	{
		str = jump_prev_delim(str, delim);
		n_str = str;
	}

	for (c = 0; str[c]; c++)
	{
		for (s = 0; delim[s]; s++)
		{
			if (str[c] == delim[s])
			{
				token = n_str;
				n_str = str + c + 1;
				str[c] = '\0';
				return (token);
			}
		}
	}
	
	if (str[c] == '\0')
	{
		token = n_str;
		n_str = NULL;
		return (token);
	}
	return (NULL);
}

/**
 * jump_prev_delim - a function that skips the previous delimiter in a string
 * @str: the string
 * @delim: the delimiter
 *
 * Return: a character type
 */

char *jump_prev_delim(char *str, const char *delim)
{
	int pnt = 0;
	int c, s, len;

	len = csh_strlen(delim);

	for (c = 0; str[c];)
	{
		for (s = 0; delim[s]; s++)
		{
			if (str[c] == delim[s])
			{
				str = str + 1;
				s = -1;
			}
			else if (s == len - 1)
			{
				pnt = 1;
				break;
			}
		}
		if (pnt == 1)
		{
			break;
		}
	}
	return (str);
}

/**
 * csh_strstr - a function that finds the initial occurence of a substring
 * needle in a string haystack
 * @haystack: the string that finds a substring
 * @needle: a substring to be found by a string
 *
 * Return: a character type
 */

char *csh_strstr(char *haystack, const char *needle)
{
	int a;
	char *c_haystack;

	if (haystack == NULL || needle == NULL)
	{
		return (NULL);
	}

	c_haystack = haystack;

	for (a = 0; c_haystack[a]; a++)
	{
		if (c_haystack[a] == *needle)
		{
			return (c_haystack + (a + 1));
		}
	}

	return (NULL);
}
