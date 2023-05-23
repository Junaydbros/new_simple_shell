#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* execmd prototype */
void _execmd(char **tok_arr);
char *get_path(char *cmd);

#endif
