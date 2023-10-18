#include "s_shell.h"
/**
 * isFile - This function checks if a paticular name is a file
 * @filename: the name of a file
 *
 * Return: the number of bytes
 *
 **/
int isFile(char *filename)
{
	int k, st_l;

	st_l = _strlen(filename);

	for (k = 0; k < st_l; k++)
	{
		if (filename[k] == '/')
		{
			return (isExecutable(filename));
		}
	}

	return (-10);
}


/**
 * isExecutable - This function checks if a file is executable
 * @name: the name
 *
 * Return: 1 or -1
 *
 **/
int isExecutable(char *name)
{
	struct stat st;

	if (stat(name, &st) == 0)
	{
		if (st.st_mode & X_OK)
		{
			return (1);
		}
		else
		{
			return (-1);
		}
	}

	return (-1);
}
