#include "clish.h"

/**
 * clish_grep - a function that handles grep in the clish SHELL terminal
 * @args: argument string
 *
 * Return: an integer type
 */

int clish_grep(char **args)
{
	FILE *fp = NULL;
	int flag = 0;
	char tempo[512];
	int line_numb = 1;

	if (args[0] != NULL && strcmp(args[0], "grep") == 0)
	{
		if (args[1] != NULL && args[2] != NULL)
		{
			fp = fopen(args[2], "r");

			while ((fgets(tempo, 512, fp)) != NULL)
			{
				if (strstr(tempo, args[1]))
				{
					printf("%d. %s", line_numb, tempo);
					flag = 1;
				}
				line_numb++;
			}
			fclose(fp);
		}

		else
		{
			fprintf(stderr, "clish: grep requires more than one parameter,");
			fprintf(stderr, " PATTERN and FILE\n");
		}
	}

	if (flag == 0)
	{
		printf("No related matches found \n");
	}

	return (1);
}
