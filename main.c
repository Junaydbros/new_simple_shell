#include "main.h"

/**
 * main - building a simple shell
 * Return: 0 on success
 */

int main(void)
{
	char *call_on = "simshell:~# ", *lineptr = NULL, *c_lineptr = NULL, *tok;
	char **tok_arr;
	size_t a = 0;
	ssize_t read_chars;
	const char *delim = " ";
	int i, tok_count = 0;

	while (1)
	{
		printf("%s", call_on);
		read_chars = getline(&lineptr, &a, stdin);
		if (read_chars == -1)
		{
			printf("exit...\n\n\nexit.\n");
			return (-1);
		}
		c_lineptr = malloc(sizeof(char) * read_chars);
		if (c_lineptr == NULL)
			return (-1);
		strcpy(c_lineptr, lineptr);
		tok = strtok(lineptr, delim);
		while (tok != NULL)
		{
			tok_count++;
			tok = strtok(NULL, delim);
		}
		tok_count++;
		tok_arr = malloc(sizeof(char *) * tok_count);
		tok = strtok(c_lineptr, delim);
		for (i = 0; tok != NULL; i++)
		{
			tok_arr[i] = malloc(sizeof(char) * strlen(tok));
			strcpy(tok_arr[i], tok);
			tok = strtok(NULL, delim);
		}
		tok_arr[i] = NULL;
		_execmd(tok_arr);
		free(c_lineptr);
		free(lineptr); }
	return (0);
}
