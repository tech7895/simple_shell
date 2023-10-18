#include "s_shell.h"

/**
 * handle_pattern - This function handles the  pattern
 * @b_type: a struct
 * @words: the parameters
 *
 * Return: the words
**/
char *handle_pattern(b_shell_t *b_type, char *words)
{
	int k;

	for (k = 0; words[k] != '\0'; k++)
	{
		if (words[k] == '$' && words[k + 1] != '\0')
		{
			words = subtituteValue(b_type, &k, words);
		}
	}

	return (words);
}

/**
 * signatures - This function handles signatures
 * @num: the number
 *
 * Return: void
 *
 **/

void signatures(int num)
{
	(void) num;

	signal(SIGINT, signatures);
	display("\n$ ");
	fflush(stdout);
}
