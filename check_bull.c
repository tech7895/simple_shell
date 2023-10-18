#include "s_shell.h"

/**
 * sysFunction - This function checks for exec builtins
 * @b_type: a struct
 * @args: the command argument
 *
 * Return: 1 or 0
 *
 **/
int sysFunction(b_shell_t *b_type, char **args)
{
	int lt;

	lt = verfbltin(b_type, args);
	if (lt == 0)
	{
		return (0);
	}
	return (1);
}


/**
 * verfbltin - This function confirms a builtin cmd
 * @b_type: a struct
 * @args: arguments
 *
 * Return: 1 or 0
 *
 **/
int verfbltin(b_shell_t *b_type, char **args)
{
	int k, gap;

	systems_t builtins[] = {
		{"exit", binaryExit},
		{"env", binaryEnv}
	};

	gap = sizeof(builtins) / sizeof(builtins[0]);
	k = 0;
	while (k < gap)
	{
		if (_strcmp(b_type->cmd, builtins[k].cmd) == 0)
		{
			builtins[k].func(b_type, args);
			return (1);
		}
		k++;
	}
	return (0);
}
