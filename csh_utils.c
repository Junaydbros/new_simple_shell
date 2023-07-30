#include "clish.h"

/**
 * csh_strlen - a function that prints the length of a string
 * @str: the string whose length is to be determined
 *
 * Return: a struct type
 */

size_t csh_strlen(const char *str)
{
	size_t cnt = 0;

	do {
		cnt++;
		str++;
	} while (*str != '\0');

	return (cnt);
}

/**
 * csh_strcpy - a function that copies a string
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a character type
 */

char *csh_strcpy(char *dest, const char *src)
{
	char *m = dest;

	do {
		*m++ = *src++;
	} while (*src != '\0');

	return (dest);
}

/**
 * csh_strcat - a function that concatenates a string
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a character type
 */

char *csh_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';

	return (dest);
}

/**
 * csh_strdup - a function that duplicates a string
 * @str: the string to be dupliucated
 *
 * Return: a character type
 */

char *csh_strdup(char *str)
{
	size_t len = csh_strlen(str);
	char *n_str = malloc(sizeof(char) * (len + 1));

	if (n_str == NULL)
	{
		return (NULL);
	}
	csh_strcpy(n_str, str);

	return (n_str);
}

/**
 * csh_strcmp - a function that comapres two strings
 * @s1: the first string to be compared
 * @s2: the second string to be compared
 *
 * Return: an integer type
 */

int csh_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
	{
		return (-1);
	}

	do {
		s1++;
		s2++;
	} while (*s1 && (*s1 == *s2));

	return (*s1 - *s2);
}
