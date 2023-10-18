#include "s_shell.h"
/**
 * evaluate - This function analyses on the arguments
 * @args: an argument
 * @b_type: a struct
 * @buffer: a buffer
 *
 * Return: void
 **/
void evaluate(char **args, b_shell_t *b_type, char *buffer)
{
	char *cmd;
	int new;

	if (*args == NULL || args == NULL)
	{
		return;
	}
	cmd = args[0];
	b_type->cmd = cmd;
	if (verfbltin(b_type, args) == 1)
	{
		return;
	}
	new = isFile(cmd);
	if (new == 0)
	{
		b_type->c_status = 126;
		b_type->e_dig = 13;
		issue(b_type);
		return;
	}
	if (new == 1)
	{
		run(cmd, args, b_type, buffer);
		return;
	}
	if (getDir(cmd, args, buffer, b_type) == 1)
		return;
	b_type->path_cmd = choose(cmd, b_type);
	if (b_type->path_cmd != NULL)
	{
		run(b_type->path_cmd, args, b_type, buffer);
		releasemem((void *) b_type->path_cmd);
		return;
	}
	b_type->c_status = 127;
	b_type->e_dig = 132;
	issue(b_type);
}
