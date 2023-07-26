#include "main.h"

/**
 * main - main shell
 * @arc: parameter 1
 * @arv: parameter 2
 * Return: 1
 */

int main(int arc, char **arv)
{
	char *comand;

	(void)arc;
	(void)arv;


	do {
		prompt1();
		comand = read_comand();
		if (!comand)
			exit(EXIT_SUCCESS);

		if (comand[0] == '\0' || strcmp(comand, "\n") == 0)
		{
			free(comand);
			continue;
		}

		if (strcmp(comand, "exit\n") == 0)
		{
			free(comand);
			break;
		}

		printf("%s\n", comand);
		free(comand);
	} while (1);

exit(EXIT_SUCCESS);
}
