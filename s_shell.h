#ifndef S_SHELL_H
#define S_SHELL_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>


#define _NO_CMD_ "not found"
#define _N_INVALID_ "Illegal number"
#define _PD_ "Permission denied"
#define _NOT_FOUND_ "No such file or directory"

typedef struct __attribute__((__packed__))
{
	int argc;
	char **argv;
	char *cmd;
	char *path_cmd;
	char *buf;
	char **targs;
	char *env;
	int pid;
	int it_mode;
	int n_cmd;
	int c_path;
	int c_status;
	int e_dig;
} b_shell_t;

typedef struct __attribute__((__packed__))
{
	char *msg;
	int password;
} stat_t;

typedef struct __attribute__((__packed__))
{
	char *cmd;
	void (*func)(b_shell_t *b_type, char **arguments);
} systems_t;

extern char **environ;
char *choose(char *dirname, b_shell_t *b_type);
void isCurrPath(char *pat, b_shell_t *b_type);
void fetchFullEnv(void);
void binaryEnv(b_shell_t *b_type, char **args);
int sysFunction(b_shell_t *b_type, char **args);
int verfbltin(b_shell_t *b_type, char **args);
void evaluate(char **args, b_shell_t *b_type, char *buffer);
int _atoi(char *s);
void signatures(int num);
int writeCharacter(char xer);
int display(char *message);
int displayError(char *message);
void getInput(b_shell_t *b_type);
int writeCharacterToFD(char cha, int fil_d);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int outputToFD(char *message, int fil_d);
int isExecutable(char *name);

void analyzePattern(b_shell_t *b_type, char **args);
char *handle_pattern(b_shell_t *b_type, char *words);
char *subtituteValue(b_shell_t *info, int *id, char *str);
void releasemem(void *pointer);
void releasememptr(void **pointer);
void binaryExit(b_shell_t *b_type, char **args);
int handle_num(b_shell_t *b_type, char *argument);
void run(char *cmd, char **argu, b_shell_t *b_type, char *buffer);
int getDir(char *command, char **argu, char *buff, b_shell_t *b_type);
void issue(b_shell_t *b_type);

char *_toString(int numbe);
int isNumeric(unsigned int number);
int hasLetter(char *string);
char **tokenize_words(char *string, const char *del);
char *mergeWords(char *w1, char *w2, char *w3, const char *del);
char *parse_prompt(void);
void init_prompt(b_shell_t *b_type);
char *selectMessage(b_shell_t b_type);
void addErr(b_shell_t *b_type, char *more);
char *getEnv(const char *variable);
void begin(b_shell_t *b_type);
int number(int num);
int isFile(char *filename);
char *exchange(b_shell_t *b_type, int *id, char *word);
void *_realloc(void *ptr, unsigned int size1, unsigned int size2);
char *subEnv(b_shell_t *b_type, char *envi_var);

#endif
