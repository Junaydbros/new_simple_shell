#ifndef CLISH_H
#define CLISH_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>

#include "structs.h"

extern char **environ;

/* clish functions */
void input_param(char **, char *);
void pipe_input_param(char *);
void freeLAP(char **args, char *lineptr, char *argv, int exe_cnt,
		char **clish, char *c_lineptr);
void err_handler(char *arg, int exit_param);
void ctrl_handle(int);
void get_dir(char *);

char *get_input_param_path(char *);
char *get_path(char *);
char *set_param_path(char **);

int input_param_count(char *);

int clish_cd(char **);
int clish_exit(char **);
int clish_help(char **);
int clish_launcher(char **);
int clish_execute(char **args, char *lineptr, char *argv, int exe_cnt,
		char **clish, char *c_lineptr);
int clish_history(int);
int clish_grep(char **);
int clish_pipe(char **);
int clish_path(char **);
int clish_otherexec(char **args, char *lineptr, char *argv, int exe_cnt,
	char **clish, char *c_lineptr);
int cli_handler(char *, char **);
int errmsg_handler(char *, int, char *, char *);

char **pipe_split(char *);
char **line_split(char *);
char *line_reader(char *);
char **tokenprinter(char *);
char *clish_env_str(const char *name, const char *val);

env_list *clish_environ(char **str);

char **set_clish_envarray(char **str);
char *getstrpath(const char *name);
char *clish_getpath(char *var);
int count_array_elem(char **arr);
void free_arr(char *arr);

int set_clish_env(const char *name, const char *val, int owrite);
int main(__attribute__((unused))int argc, char **argv);

char *csh_strtok(char *, const char *);
char *csh_strstr(char *, const char *);
char *jump_prev_delim(char *, const char *);
int *whitespace_trim(char *);
int arg_len(char **);

char *csh_strdup(char *str);
char *atioa(int numb);
char *csh_strcpy(char *dest, const char *src);
char *csh_strcat(char *dest, const char *src);
int csh_strcmp(const char *s1, const char *s2);
size_t csh_strlen(const char *str);

int _putchar(char c);
int _puts(char *str);

/* For Junaydbros and Kamma */
#endif
