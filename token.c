#include "main.h"

char *tok_buf = NULL;
int   tok_bufsize  = 0;
int   tok_bufindex = -1;

token_s eof_token = { NULL, 0, NULL };

/**
 * add_to_buf - adds single character to token buffer
 * @c: passed parameter
 */

void add_to_buf(char c)
{
	char *tmp = realloc(tok_buf, tok_bufsize * 2);

	tok_buf[tok_bufindex++] = c;

	if (tok_bufindex >= tok_bufsize)
	{

		if (!tmp)
		{
			errno = ENOMEM;
			return;
		}

		tok_buf = tmp;
		tok_bufsize *= 2;
	}
}


/**
 * create_token - converts string to token_s struct
 * @str: passed parameter
 * Return: converted string
 */

token_s *create_token(char *str)
{
	token_s *tok = malloc(sizeof(token_s));
	char *ntext = malloc(tok->len_text + 1);

	if (!tok)
		return (NULL);

	memset(tok, 0, sizeof(token_s));
	tok->len_text = strlen(str);

	if (!ntext)
	{
		free(tok);
		return (NULL);
	}

	strcpy(ntext, str);
	tok->text = ntext;

	return (tok);
}


/**
 * free_token - frees memory for token
 * @tok: token
 */

void free_token(token_s *tok)
{
	if (tok->text)
		free(tok->text);
	free(tok);
}


/**
 * tokenize - tokenizing the input
 * @src: input
 * Return: the token
 */

token_s *tokenize(pass_s *src)
{
	int  loop_end = 0;
	char c = next_str(src);
	token_s *tok = create_token(tok_buf);

	if (!src || !src->str || !src->bufsize)
	{
		errno = ENODATA;
		return (&eof_token);
	}
	if (!tok_buf)
	{
		tok_bufsize = 1024;
		tok_buf = malloc(tok_bufsize);
		if (!tok_buf)
		{
			errno = ENOMEM;
			return (&eof_token);
		}
	}
	tok_bufindex     = 0;
	tok_buf[0]       = '\0';
	if (c == ERRCHAR || c == EOF)
		return (&eof_token);
	do {
		switch (c)
		{
			case ' ':
			case '\t':
				if (tok_bufindex > 0)
					loop_end = 1;
				break;
			case '\n':
				if (tok_bufindex > 0)
					unget_str(src);
				else
					add_to_buf(c);
				loop_end = 1;
				break;
			default:
				add_to_buf(c);
				break;
		}
		if (loop_end)
			break;
	} while ((c = next_str(src)) != EOF);
	if (tok_bufindex == 0)
		return (&eof_token);
	if (tok_bufindex >= tok_bufsize)
		tok_bufindex--;
	tok_buf[tok_bufindex] = '\0';
	if (!tok)
	{
		fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
		return (&eof_token);
	}
	tok->src = src;
	return (tok);
}
