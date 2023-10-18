#include "s_shell.h"

/**
 * binaryExit - This function helps to exit the shell
 * Description: it releases memmory and exit
 * @b_type:a struct
 * @args: the argument
 *
 * Return: void
 *
 **/
void binaryExit(b_shell_t *b_type, char **args)
{
	int status, status_dail;

	status = 1;
	if (args[1] != NULL)
	{
		status = handle_num(b_type, args[1]);
	}

	if (status == 0)
	{
		return;
	}

	status_dail = b_type->c_status;

	releasememptr((void **) args);
	releasemem((void *) b_type->buf);
	releasemem((void *) b_type->env);
	releasemem((void *) b_type);

	exit(status_dail);
}
