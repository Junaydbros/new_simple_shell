#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "struct.h"


#define EOF		(-1)
#define ERRCHAR		( 0)
#define INIT_SRC_POS	(-2)




/* prompt.c */
void prompt1(void);
void prompt2(void);


/* read_cmd.c */
char *read_comand(void);


/* pass.c */
void unget_str(pass_s *src);
char next_str(pass_s *src);
char peek_str(pass_s *src);
void skip_white_spaces(pass_s *src);


/* token.c */
void add_to_buf(char c);
token_s *create_token(char *str);
void free_token(token_s *tok);
token_s *tokenize(pass_s *src);

#endif
