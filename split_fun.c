#include "s_shell.h"

/**
 * tokenize_words - This function splits a string into
 * words based on a delimeter
 * @string: input string
 * @del: the delimiter
 *
 * Return: the splited words
 *
 **/

char **tokenize_words(char *string, const char *del)
{
	unsigned int first, second;
	char **word, **temp, *token;

	first = sizeof(char *);
	word = malloc(first);
	if (word != NULL)
	{
		second = 1;
		token = strtok(string, del);
		while (token)
		{
			if (token[0] == '#')
				break;
			temp = _realloc(word, first, (second + 1) * sizeof(char *));
			first = (second + 1) * sizeof(char *);
			if (temp == NULL)
				break;
			word = temp;
			++second;

			word[second - 2] = malloc(_strlen(token) + 1);
			if (word == NULL)
			{
				free(word);
				free(temp);
			}

			if (word[second - 2] != NULL)
			{
				_strcpy(word[second - 2], token);
			}
			token = strtok(NULL, del);
			temp = NULL;
		}
		word[second - 1] = NULL;
	}
	return (word);
}
