#include "main.h"

/**
 * read_comand - read the user's input
 * Return: the pointer
 */

char *read_comand(void)
{
	char buff[1024], ptrlen = 0;
	char *ptr = NULL, *ptr2;
	int bufflen;

	while (fgets(buff, 1024, stdin))
	{
		bufflen = strlen(buff);
		if (!ptr)
			ptr = malloc(bufflen + 1);
		else
		{
			ptr2 = realloc(ptr, ptrlen + bufflen + 1);
			if (ptr2)
				ptr = ptr2;
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}
		if (!ptr)
		{
			fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
			return (NULL);
		}
		strcpy(ptr + ptrlen, buff);
		if (buff[bufflen - 1] == '\n')
		{
			if (bufflen == 1 || buff[bufflen - 2] != '\\')
				return (ptr);
			ptr[ptrlen + bufflen - 2] = '\0';
			bufflen -= 2;
			prompt2();
		}
		ptrlen += bufflen;
	}
	return (ptr);
}
