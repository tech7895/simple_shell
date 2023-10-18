#include "s_shell.h"
/**
 * run - This function executes a command in the child process
 * @cmd: the command
 * @argu: the arguments
 * @b_type: a struct
 * @buffer: the buffer
 *
 * Return: void
 *
 **/
void run(char *cmd, char **argu, b_shell_t *b_type, char *buffer)
{
	int cond;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, argu, environ);
		perror("./sh");

		releasememptr((void *) argu);

		if (b_type->path_cmd != NULL)
		{
			free(b_type->path_cmd);
			b_type->path_cmd = NULL;
		}

		free(b_type);
		free(buffer);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &cond, 0);
		if (WIFEXITED(cond))
		{
			b_type->c_status = WEXITSTATUS(cond);
		}
	}
}
