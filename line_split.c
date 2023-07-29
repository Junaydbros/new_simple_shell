#include "clish.h"

/**
 * line_split - function to split lines
 * @line: line to split
 *
 * Return: a character type
 */

/**
 * char **line_split(char *line)
* {
*	int buffsize = TKN_BUFF_SIZE, posit = 0;
*	char **tokenn = malloc(buffsize * sizeof(char *));
*	char *token;
*
*	if (!tokenn)
*	{
*		fprintf(stderr, "clish: Error with allocation\n");
*		exit(EXIT_FAILURE);
*	}
*	token = strtok(line, TKN_DELIM);
*
*	while (token != NULL)
*	{
*		tokenn[posit] = token;
*		posit++;
*
*		if (posit >= buffsize)
*		{
*			buffsize = buffsize + TKN_BUFF_SIZE;
*			tokenn = realloc(tokenn, buffsize * sizeof(char *));
*
*			if (!tokenn)
*			{
*				fprintf(stderr, "clish: Error with Allocation\n");
*				exit(EXIT_FAILURE);
*			}
*		}
*
*		token = strtok(NULL, TKN_DELIM);
*	}
*
*	tokenn[posit] = NULL;
*
*	return (tokenn);
* }
*/


/**
 * tokenprinter - a function that prints tokens
 * @tokenn: to be tokenized
 *
 * Return: a void type
 */

char **tokenprinter(char *tokenn)
{
	char *delim;
	char *str_d, *token;
	char **arv;
	int b = 0;

	str_d = csh_strdup(tokenn);

	if (str_d == NULL)
	{
		free(tokenn);
		err_handler("Error of strdup\n", EXIT_FAILURE);
	}
	token = strtok(str_d, delim);

	while (token)
	{
		b++;
		token = strtok(NULL, delim);
	}

	arv = malloc(sizeof(char *) * (b = 0));
	if (arv == NULL)
	{
		freeLAP(NULL, NULL, tokenn, str_d, NULL);
		err_handler("Error with memory allocation", EXIT_FAILURE);
	}

	b = 0;
	token = strtok(tokenn, delim);
	while (token)
	{
		arv[b] = token;
		token = strtok(NULL, delim);
		b++;
	}
	arv[b] = NULL;
	free(str_d);

	return (arv);
}

/**
 * whitespace_trim - a function that checks for and eliminates whitespaces
 * @str: thr string to be checked
 *
 * Return: an integer type
 */

int whitespace_trim(char *str)
{
	int d, len, flag = 0;

	len = csh_strlen(str);

	for (d = 0; d < (len - 1); d++)
	{
		if (str[d] == ' ')
		{
			continue;
		}
		else
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		return (0);
	}
	return (1);
}

/**
 * line_reader - a function to read, process and execute user input
 * @argv: an argument name
 *
 * Return: a character type
 */

char *line_reader(char *argv)
{
	int exe_cnt;
	int flag, clish_cnt, a, stat = 1;
	char *e_lineptr, *c_lineptr, *lineptr = NULL;
	char *delim = " \n";
	char **clish, **arv;
	size_t m = 0;

	if (getline(&lineptr, &m, stdin) == -1)
	{
		free(lineptr);
		return (0);
	}

	flag = whitespace_trim(lineptr);
	if (flag == 1)
	{
		free(lineptr);

		return (1);
	}
	if (lineptr[0] == '\n')
	{
		free(lineptr);

		return (1);
	}
	c_lineptr = csh_strdup(lineptr);
	clish = tokenprinter(c_lineptr, "&;\n");
	clish_cnt = arr_counter(clish);

	free(lineptr);

	for (a = 0; a < clish_cnt; a++)
	{
		e_lineptr = csh_strdup(clish[a]);
		arv = tokenprinter(e_lineptr, delim);
		stat = clish_inbuilt(arv, e_lineptr, argv, exe_cnt, clish, c_lineptr);
	}
	return (stat);
}
