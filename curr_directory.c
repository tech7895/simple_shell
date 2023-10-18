#include "s_shell.h"
/**
 * getDir - This function gets the directory
 * @command: a command
 * @argu: a argument
 * @buff: the buffer
 * @b_type: a struct
 *
 * Return: 1 or 0
 **/
int getDir(char *command, char **argu, char *buff, b_shell_t *b_type)
{

	if (b_type->c_path == 0)
	{
		return (0);
	}

	if (isExecutable(command) == 1)
	{
		run(command, argu, b_type, buff);
		return (1);
	}

	return (0);
}
