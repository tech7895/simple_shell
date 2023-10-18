#include "s_shell.h"

/**
 * getInput - This function serves as a prompt
 * @b_type: a struct
 *
 * Return: void
 *
 **/
void getInput(b_shell_t *b_type)
{
	if (b_type->it_mode == 0)
	{
		return;
	}

	display("$ ");
}


/**
 * parse_prompt - This function uses the getline function
 * to read the line of the prompt
 *
 * Description: it handles the end of file
 *
 * Return: the buff
 *
 **/
char *parse_prompt(void)
{
	char *buf = NULL;
	int ret;
	size_t size;

	ret = getline(&buf, &size, stdin);

	if (ret == EOF)
	{
		releasemem((void *) buf);
		return (NULL);
	}

	return (buf);
}
