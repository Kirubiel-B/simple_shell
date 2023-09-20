#include "simple_shell.h"

/**
 * kap - starts executing everything
 * @kaq: try to check current token
 * @kar: parse token
 *
 * Return: void function
 */

void kap(char **kaq, int kar)
{
	pid_t PID;

	if (kar == KA || kar == KC)
	{
		PID = fork();
		if (PID == 0)
			kai(kaq, kar);
		else
		{
			waitpid(PID, &ko, 0);
			ko >>= 8;
		}
	}
	else
		kai(kaq, kar);
}
