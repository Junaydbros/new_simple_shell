#ifndef STRUCT_H
#define STRUCT_H

/**
 * struct pass_str - passing the input string
 * @str: input string
 * @bufsize: size of input string
 * @strpos: absolute char position in source
 */

typedef struct pass_str
{
	char *str;
	long bufsize;
	long strpos;
} pass_s;


/**
 * struct token_str - extracting input tokens
 * @src: input
 * @len_text: length of text
 * @text: text
 */

typedef struct token_str
{
	pass_s *src;
	int len_text;
	char *text;
} token_s;



/* special token to indicate end of input */

#endif
