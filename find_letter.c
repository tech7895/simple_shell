#include "s_shell.h"
/**
 * hasLetter - This function searchs if a string contains letter
 * @string: the string
 * Return: 1 or 0
 *
 **/
int hasLetter(char *string)
{
	int iter;

	for (iter = 0; string[iter] != '\0'; iter++)
	{
		if (isNumeric(string[iter]) == 0)
			return (1);
	}

	return (0);
}
