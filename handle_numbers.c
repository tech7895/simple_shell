#include "s_shell.h"

/**
 * number - This function returns the number of digits
 *
 * @num: the number
 *
 * Return: the number of digits
 *
 **/
int number(int num)
{
	int iter = 0;

	while (num != 0)
	{
		iter++;
		num = num / 10;
	}

	return (iter);
}


/**
 * manageNumbers - This function Controls the argument of the exit builtin
 * @b_type: a struct
 * @argument: the argument
 *
 * Return: 1 or 0
 *
 **/

int manageNumbers(b_shell_t *b_type, char *argument)
{
	int t;

	t = _atoi(argument);

	if (t < 0 || hasLetter(argument))
	{
		b_type->c_status = 2;
		b_type->e_dig = 133;
		additionalError(b_type, argument);
		return (0);
	}

	if (t > 255)
	{
		b_type->c_status = t % 256;
	}
	else
	{
		b_type->c_status = t;
	}

	return (1);
}


/**
 * isNumeric - This function checks if a given parameter is a digit
 * @number: the number
 *
 * Return: the digit
 *
 */
int isNumeric(unsigned int number)
{
	return (number >= '0' && number <= '9');
}


/**
 * _atoi - This function converts a string to an integer
 * @s: the string to be converted
 * Return: the converted string
 */
int _atoi(char *s)
{
	size_t counter = 0, len = 0, i = 0, j = 1, m = 1, k;

	while (s[counter] != '\0')
	{
		if (len > 0 && (s[counter] < '0' || s[counter] > '9'))
			break;

		if (s[counter] == '-')
			j *= -1;

		if (s[counter] >= '0' && s[counter] <= '9')
		{
			if (len > 0)
				m *= 10;
			len++;
		}
		counter++;
	}

	for (k = counter - len; k < counter; k++)
	{
		i = i + ((s[k] - '0') * m);
		m /= 10;
	}
	return (i * j);
}
