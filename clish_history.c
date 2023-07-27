#include "clish.h"

/**
 * clish_history - function that shows history of recently entered commands and
 * awaits user input
 *
 * Return: an integer type
 */

char *clr[2] = {"clear", NULL};

int clish_history(void)
{
	FILE *fp = fopen(get_input_param_path(), "r");
	int ch, c, line_numb = 1;

	char line[128];
	char prev_comm[128];
	char **args = NULL;

	if (!fp)
	{
		fprintf(stderr, "file not found\n");
	}
	else
	{
		putchar('\n');
		while ((c = getc(fp)) != EOF)
		{
			putchar(c);
		}
	}
	printf("\n <0>: Exit	<#line>: Exec cmd	<-1>: cls \n\n: ");
	scanf("%d", &ch);
	getchar();
	fseek(fp, 0, SEEK_SET);

	if (isdigit(ch) != 0)
	{
		printf("Kindly enter a number\n");
	}
	else if (ch == 0)
	{
		fclose(fp);
		return (1);
	}
	else if (ch == -1)
	{
		fclose(fp);
		fp = fopen(get_input_param_path(), "w");
		fclose(fp);
		return (clish_execute(clr));
	}
	else
	{
		while ((fgets(line, 128, fp)) != NULL)
		{
			if (line_numb == ch)
			{
				strcpy(prev_comm, &line[3]);
				int l = 0, flag = 0;

				fclose(fp);

				while (prev_comm[l] != '\0')
				{
					if (prev_comm[l] == '|')
					{
						flag = 1;
						break;
					}
					l++;
				}
				if (!flag)
				{
					args = line_split(prev_comm);
					return (clish_launcher(args));
				}
				else
				{
					args = pipe_split(prev_comm);
					return (clish_pipe(args));
				}
			}
			else
			{
				line_numb++;
			}
		}
	}
	return (1);
}

/**
 * clish_execute - function that executes commands input on the clish terminal
 * @args: an argument string
 *
 * Return: an integer type

int clish_execute(char **args)
{
	pid_t pid;
	int stat;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) < 0)
		{
			printf("clish: Unidentified command: %s\n", args[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		printf("Fork Error\n");
	}
	else
	{
		waitpid(pid, &stat, WUNTRACED);
	}
	return (1);
} */
