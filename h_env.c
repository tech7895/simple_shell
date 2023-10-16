#include "s_shell.h"
/**
 * fetchFullEnv - This function gets all the environment variables
 *
 * Return: void
 *
 **/
void fetchFullEnv(void)
{
	int j = 0;
	char **temp;

	for (j = 0, temp = environ; temp[j] != NULL; j++)
	{
		display(temp[j]);
		writeCharacter('\n');
	}
}

/**
 * getEnv - This function gets an environment variable
 *
 * @variable: the variable
 *
 * Return: name or NULL
 *
 **/
char *getEnv(const char *variable)
{
	char **enviro, *aux, *t, *w;
	int k;

	k = _strlen((char *) variable);

	for (enviro = environ; *enviro; ++enviro)
	{
		aux = _strdup(*enviro);

		t = strtok(aux, "=");
		if (t == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (_strlen(t) != k)
		{
			free(aux);
			continue;
		}
		if (_strcmp((char *) variable, aux) == 0)
		{
			t = strtok(NULL, "=");
			w = _strdup(t);
			free(aux);
			return (w);
		}
		free(aux);
	}
	return (NULL);
}


/**
 * binaryEnv - This function implements the builtin of the environment
 *
 * @b_type: a struct
 * @args: argument
 *
 * Return: void
 **/
void binaryEnv(b_shell_t *b_type, char **args)
{
	(void) b_type;
	(void) args;

	fetchFullEnv();
}
