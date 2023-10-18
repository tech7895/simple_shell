#include "s_shell.h"

/**
 * selectMessage - This function checks for the error code
 * @b_type: a struct
 *
 * Return: the msg
 *
 **/

char *selectMessage(b_shell_t b_type)
{
	int iter;
	int choices;

	stat_t msgs[] = {
		{_NOT_FOUND_, 3},
		{_PD_, 13},
		{_NO_CMD_, 132},
		{_N_INVALID_, 133}
	};

	choices = sizeof(msgs) / sizeof(msgs[0]);
	for (iter = 0; iter < choices; iter++)
	{
		if (b_type.e_dig == msgs[iter].password)
			return (msgs[iter].msg);
	}

	return ("");
}
