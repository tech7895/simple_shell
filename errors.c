#include "s_shell.h"

/**
 * issue - This function displays the error encountered
 * @b_type: a struct
 *
 * Return: void
 *
 **/
void issue(b_shell_t *b_type)
{
	char *msg, *num, *au;
	int sn, sm;

	num = NULL;
	msg = selectMessage(*b_type);
	num = _toString(b_type->n_cmd);

	sn = _strlen(num);
	sm = _strlen(b_type->argv[0]);

	au = malloc(sm + sn + 3);

	au = _strcpy(au, b_type->argv[0]);
	au = _strcat(au, ": ");
	au = _strcat(au, num);

	msg = mergeWords(au, b_type->cmd, msg, ": ");
	displayError(msg);

	free(msg);
	free(num);
	free(au);
}

/**
 * displayError - This function prints out the standard error
 *
 * @message: the message
 *
 * Return: the umber of byte
 *
 **/
int displayError(char *message)
{
	return (outputToFD(message, 2));
}

/**
 * addErr - This function Prints the error message
 * @b_type: a struct
 * @more: the information
 *
 * Return: void
 **/
void addErr(b_shell_t *b_type, char *more)
{
	char *messag, *n1, *au, *au2;
	int n1_size, messag_size;
	int size_ad;

	n1 = NULL;
	messag = selectMessage(*b_type);
	n1 = _toString(b_type->n_cmd);

	n1_size = _strlen(n1);
	messag_size = _strlen(b_type->argv[0]);
	size_ad = _strlen(more);

	au = malloc(messag_size + n1_size + 3);
	au = _strcpy(au, b_type->argv[0]);
	au = _strcat(au, ": ");
	au = _strcat(au, n1);

	au2 = malloc(_strlen(messag) + size_ad + 3);
	au2 = _strcpy(au2, messag);
	au2 = _strcat(au2, ": ");
	au2 = _strcat(au2, more);

	messag = mergeWords(au, b_type->cmd, au2, ": ");

	displayError(messag);

	free(messag);
	free(n1);
	free(au);
	free(au2);
}
