#include "s_shell.h"

/**
 * _strdup - This function copies a string
 * @str: the string to copy
 *
 *  Return: the dest string
 *
 **/
char *_strdup(char *str)
{
	char *dest;
	int size, i;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = (char *)malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		dest[i] = str[i];

	return (dest);
}
