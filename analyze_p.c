#include "s_shell.h"

/**
 * analyzePattern - This function analyzes a pattern
 * @b_type: the  input
 * @args: the argument
 *
 * Return: void
 *
**/
void analyzePattern(b_shell_t *b_type, char **args)
{
	int k;

	for (k = 0; args[k] != NULL; k++)
	{
		args[k] = handle_pattern(b_type, args[k]);
	}
}
