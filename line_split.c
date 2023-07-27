#include "clish.h"

/**
 * line_split - function to split lines
 * @line: line to split
 *
 * Return: acharacter type
 */

char **line_split(char *line)
{
	int buffsize = TKN_BUFF_SIZE, posit = 0;
	char **tokenn = malloc(buffsize * sizeof(char *));
	char *token;

	if (!tokenn)
	{
		fprintf(stderr, "clish: Error with allocation\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TKN_DELIM);

	while (token != NULL)
	{
		tokenn[posit] = token;
		posit++;

		if (posit >= buffsize)
		{
			buffsize = buffsize + TKN_BUFF_SIZE;
			tokenn = realloc(tokenn, buffsize * sizeof(char *));

			if (!tokenn)
			{
				fprintf(stderr, "clish: Error with Allocation\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TKN_DELIM);
	}

	tokenn[posit] = NULL;

	return (tokenn);
}

/**
 * tokenprinter - a test function for split_line
 * @tokenn: to be tokenized
 *
 * Return: a void type
 */

void tokenprinter(char **tokenn)
{
	int b = 0;

	while (tokenn[b] != NULL)
	{
		printf("%s\n", tokenn[b]);
		b++;
	}
}

/*
 * line_reader - function to read between lines
 *
 * Return: a character type
 */

char *line_reader()
{
	int buffsize = RL_BUFF_SIZE;
	int posit = 0;
	int bc;
	char *buffer = malloc(sizeof(char) * buffsize);

	if (!buffer)
	{
		fprintf(stderr, "clish: Error in Allocation\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		bc = getchar();

		if (bc == EOF || bc == '\n')
		{
			buffer[posit] = '\0';
			return (buffer);
		}
		else
		{
			buffer[posit] = bc;
		}
		posit++;

		if (posit >= buffsize)
		{
			printf("Buffer Overflow has occured...need to allocate more memory\n");

			printf("\nNow Allocating more memory...\n");
			buffsize = buffsize + RL_BUFF_SIZE;
			buffer = realloc(buffer, buffsize);

			if (!buffer)
			{
				fprintf(stderr, "clish: Error in Allocation\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
