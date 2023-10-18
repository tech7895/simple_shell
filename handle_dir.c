#include "s_shell.h"
/**
 * choose - This function searches from directories
 * @dirname: a directory name
 * @b_type: a struct
 * Return: NULL
 */
char *choose(char *dirname, b_shell_t *b_type)
{
	char *path, *path_temp, *tkn, *del;
	int gap;

	(void) b_type;

	path = getEnv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}

	tkn = strtok(path, ":");

	gap = _strlen(dirname) + 2;
	del = malloc(gap * sizeof(char));
	del = _strcpy(del, "/");
	del = _strcat(del, dirname);

	while (tkn != NULL)
	{
		path_temp = malloc(_strlen(tkn) + gap);
		path_temp = _strcpy(path_temp, tkn);
		path_temp = _strcat(path_temp, del);

		if (isExecutable(path_temp) == 1)
		{
			free(path);
			free(del);
			return (path_temp);
		}
		tkn = strtok(NULL, ":");

		free(path_temp);
	}

	free(del);
	free(path);

	return (NULL);
}
