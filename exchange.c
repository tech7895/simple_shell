#include "s_shell.h"
/**
 * exchange - Function entry
 *
 * @b_type: a struct
 * @id: an index
 * @word: the input words
 *
 * Return: tmp
**/
char *exchange(b_shell_t *b_type, int *id, char *word)
{
	char *tmp, symbol;

	(void) id;

	symbol = *word;
	if (symbol != '?' && symbol != '$')
	{
		tmp = subEnv(b_type, word);
		return (tmp);
	}

	tmp = (symbol == '$') ? _toString(b_type->pid) :

		_toString(b_type->c_status);

	return (tmp);
}
