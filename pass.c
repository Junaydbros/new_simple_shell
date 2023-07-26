#include "main.h"

/**
 * unget_str - returns the last character retrieved from input
 * @src: passed parameter
 */

void unget_str(pass_s *src)
{
	if (src->strpos < 0)
		return;
	src->strpos--;
}


/**
 * next_str - changes the source pointer and returns next character of input
 * @src: passed parameter
 * Return: next character of input
 */

char next_str(pass_s *src)
{
	if (!src || !src->str)
	{
		errno = ENODATA;
		return (-ERRCHAR);
	}

	if (src->strpos == INIT_SRC_POS)
		src->strpos  = -1;

	if (++src->strpos >= src->bufsize)
	{
		src->strpos = src->bufsize;
		return (EOF);
	}

	return (src->str[src->strpos]);
}


/**
 * peek_str - returns the next character of the input
 * @src: passed parameter
 * Return: the next character of input
 */

char peek_str(pass_s *src)
{
	long p = src->strpos;

	if (!src || !src->str)
	{
		errno = ENODATA;
		return (-ERRCHAR);
	}


	if (p == INIT_SRC_POS)
		p++;
	p++;

	if (p >= src->bufsize)
		return (EOF);

	return (src->str[p]);
}


/**
 * skip_white_spaces - skip whitespace characters
 * @src: passes parameter
 */

void skip_white_spaces(pass_s *src)
{
	char b;

	if (!src || !src->str)
		return;

	while (((b = peek_str(src)) != EOF) && (b == ' ' || b == '\t'))
		next_str(src);
}
