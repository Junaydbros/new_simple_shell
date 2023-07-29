#include "clish.h"

/**
* csh_array - count element of array of strings
*
* @arr: array of strings
*
* Return: an integer type
*/

int csh_array(char **arr)
{
	int a;

	if (arr == NULL)
		return (0);

	for (a = 0; arr[a]; a++)
		;
	return (a);
}

/**
 * free_arr - free aarray of strings
 *
 * @arr: array of strings
 *
 * Return: void type
 */

void free_arr(char **arr)
{
	int a = 0;

	while (arr[a])
	{
		free(arr[a]);
		a++;
	}
	free(arr);
}
