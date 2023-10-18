#include "s_shell.h"
/**
 * main - This function is the main program
 * Description: this runs a basic shell
 * @ac: argument count
 * @av: arguments vector
 *
 * Return: the cond
 *
 **/
int main(int ac, char **av)
{
	int cond;
	b_shell_t *b_type;

	b_type = malloc(sizeof(b_shell_t));
	if (b_type == NULL)
	{
		perror(av[0]);
		exit(1);
	}

	b_type->pid = getpid();
	b_type->c_status = 0;
	b_type->n_cmd = 0;
	b_type->argc = ac;
	b_type->argv = av;
	b_type->it_mode = isatty(0) == 1;
	begin(b_type);

	cond = b_type->c_status;

	free(b_type);

	return (cond);
}
