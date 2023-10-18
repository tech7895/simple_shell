#include "s_shell.h"

/**
 * mergeWords - This function joins words with a delimiter
 * @w1: the first word
 * @w2: the second word
 * @w3: the third word
 * @del: the delimiter
 *
 * Return: the merged string
 *
 **/
char *mergeWords(char *w1, char *w2, char *w3, const char *del)
{
	int len1, len2, len3, merged;
	char *joint;

	len1 = len2 = len3 = merged = 0;

	if (w2 != NULL)
		len2 = _strlen(w2);
	else
		w2 = "";

	if (w1 != NULL)
		len1 = _strlen(w1);
	else
		w1 = "";
	if (w3 != NULL)
		len3 = _strlen(w3);
	else
		w3 = "";
	if (del != NULL)
		merged = _strlen((char *)del);
	else
		del = "";

	joint = malloc(len1 + merged + len2 + merged + len3 + 2);
	if (joint == NULL)
	{
		return (NULL);
	}
	joint = _strcpy(joint, w1);
	joint = _strcat(joint, (char *)del);
	joint = _strcat(joint, w2);
	joint = _strcat(joint, (char *)del);
	joint = _strcat(joint, w3);
	joint = _strcat(joint, "\n");

	return (joint);
}
