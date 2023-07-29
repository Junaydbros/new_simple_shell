#ifndef STRUCTS_H
#define STRUCTS_H

/**
 * struct_env - structure for environment strings
 *
 * @str: environment string
 * @nnode: the next node in a linked list
 *
 * Return: a type defined struct type
 */

typedef struct struct_env
{
	char *str;
	struct struct_env *nnode;
} env_list;

/* Junaydbros x Kamma */
#endif
