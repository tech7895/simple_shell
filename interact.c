#include "s_shell.h"

/**
 * init_prompt - This function is the main interactive prompt
 * @b_type: a struct
 *
 * Return: void
 **/

void init_prompt(b_shell_t *b_type)
{
	char *buffer, **args;
	char *p_env;

	signal(SIGINT, signatures);
	while (1)
	{
		getInput(b_type);

		p_env = getEnv("PATH");
		isCurrPath(p_env, b_type);

		b_type->env = p_env;
		buffer = parse_prompt();

		if (buffer == NULL)
		{
			display(b_type->it_mode == 1 ? "exit\n" : "");
			free(p_env);
			break;
		}
		b_type->n_cmd++;
		if (buffer[0] != '\n')
		{
			args = tokenize_words(buffer, " \t\n");

			b_type->targs = args;
			b_type->buf = buffer;
			analyzePattern(b_type, args);
			evaluate(args, b_type, buffer);
			releasememptr((void *) args);
		}
		releasemem((void *) buffer);
		releasemem((void *) p_env);
	}

}
