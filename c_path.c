#include "s_shell.h"
/**
 * isCurrPath - This function checks how the path is being arranged
 * @pat: the path
 * @b_type: a struct
 *
 * Return: void
 *
 **/
void isCurrPath(char *pat, b_shell_t *b_type)
{
	b_type->c_path = 0;

	if (pat == NULL)
	{
		return;
	}

	if (pat[0] == ':')
	{
		b_type->c_path = 1;
	}
}
