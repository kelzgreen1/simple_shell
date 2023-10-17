#ifndef  SHELL_H
#define  SHELL_H

/* all the libraries for the custom shell */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

#define BUFFER_SIZE 1024
#define CUSTOM_DELIMETERS "\t\n"
#define TOKEN_SIZE 100
#define PATH_SIZE 1050

/* prototypes used for string and print replicas*/
char *_strchr(const char *s, int ch);
char *_strtok(char *str, const char *deli);
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *tar, const char *ori);
char _atoi(const char *str);
char *_strdup(const char *s);
char *_strcat(char *trg, char *ori);
char *_strstr(const char *str, const char *n_str);
char *_strpbrk(const char *str, const char *s_str);

/* for the main function calls */

void *prompt(char *cmd);
void start(void);
int execute_cmd(char *path, char **ptr, char **str, char *name);
char **split(char *str, char **tokens);
void _puts(const char *s);
int _putchar(char ch);
int _getline(void);
void *_realloc(void *old_ptr, size_t old_size);
void sighandler(int num);
void *_memset(void *dest, int value, size_t size);

/* extra prototypes */
void prerror(char *name, char *cmd_name, int i);
char *itoa(int value, char *buffer, int radix, int is_negative);
void farray(char **str);
int count_digits(int value);
char *_pathv(char **var);
char *full_path(char **envvar, char *name, char *f_path, char *e_found);
void error_mesg(char *message, const char *name, int count, const char *command);
int cd_cmd(char **tokens, __attribute__((unused)) int *exit_status, int count, char **argv);

/* new prototypes */

void msg_cerror(char *buff, const char *name, int tracker, const char *cmd);
int cmd_handler(char **str, int *estatus, int count, char **argv);
void user_info_handler(char **env, char **argv);
void input_process(char *input_line, int *token_count, char *buff, int *estatus, int tracker, char **argv, char **str, int *b_flag);
int env_cmd(char **str, int *estatus, int count, char **argv);
int exit_cmd(char **str, int *estatus, int count, char **argv);
int _setenv_cmd(char **str, int *estatus, int tracker, char **argv);
int _unsetenv_cmd(char **str, int *estatus, int tracker, char **argv);

/* all the structures used in this shell program*/

/**
 * struct builtins_cmd - contains the class for the buildins commands
 * @cmd_name: build-in command name 
 * @ptr: it  points to the function that handles the commaand.
*/
typedef struct builtins_cmd
{
int (*ptr)(char **str, int *estatus, int count, char **argv);
char *cmd_name;

} builtins_cmd;

#endif
