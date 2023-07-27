#ifndef CLISH_H
#define CLISH_H

#include <stdio.h>
#include <stdlib.h>
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

#define TKN_BUFF_SIZE 64
#define RL_BUFF_SIZE 1024
#define TKN_DELIM " \t\r\n\a"

/* clish functions */
void input_param(char **, char *);
void pipe_input_param(char *);
void tokenprinter(char **);
void ctrl_handle();
void get_dir(char *);
void clish_loop(void);

char *get_input_param_path();
char *get_path(char *cmd);

int input_param_count();

int clish_cd(char **);
int clish_exit(char **);
int clish_help(char **);
int clish_launcher(char **);
int clish_execute(char **);
int clish_history();
int clish_grep(char **);
int clish_pipe(char **);

char **pipe_split(char *);
char **line_split(char *);
char *line_reader();
char *whitespace_trim(char *);
int arg_len(char **);

char *clr[2] = {"clear", NULL};

/* inbuilt_funct - the array of inbuilt function pointers */
int (*inbuilt_funct[])(char **) = {
	&clish_cd, &clish_help, &clish_exit, &clish_history, &clish_grep, &arg_len
};

/* inbuilt_str - aray string for strcmp() command before execvp() initiation */
char *inbuilt_str[] = {
	"sizeof", "help", "exit", "history", "cd", "grep"
};

/**
 * inbuilt_cnt - returns the inbuilt array size
 *
 * Return: an integer type
 */
int inbuilt_cnt(void)
{
	return (sizeof(inbuilt_str) / sizeof(char *));
}

/* For Junaydbros and Kamma */
#endif
