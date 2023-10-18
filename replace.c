#include "s_shell.h"
/**
 * subEnv - This funcrion is used to replace the environment variable
 * @b_type: a struct
 * @envi_var: the environment variable
 *
 * Return: NULL or var
 *
**/
char *subEnv(b_shell_t *b_type, char *envi_var)
{
	char *var;

	(void) b_type;

	var = getEnv(envi_var);
	if (var != NULL)
	{
		return (var);
	}

	return (NULL);
}

/**
 * subtituteValue - This function helps with replacing a pattern value
 * @b_type: a struct
 * @id: the id
 * @str: the string input
 *
 * Return: the string
 *
**/
char *subtituteValue(b_shell_t *b_type, int *id, char *str)
{
	char *param;
	int iter, str1, str2;

	iter = *id;
	iter++;

	param = exchange(b_type, id, str + iter);
	if (param == NULL)
	{
		str = _strcpy(str, "");

		return (str);
		;
	}

	str1 = _strlen(str);
	str2 = _strlen(param) + 1;
	str = _realloc(str, str1, str2);
	str = _strcpy(str, param);

	releasemem(param);
	*id = iter;

	return (str);
}
