#include "simple_shell.h"

/**
 * kap - function initiates the execution of the entire program.
 *
 * Parameters:
 *	@kaq: A variable used to check the current token.
 * @kar: A variable responsible for token parsing.
 *
 * Return:
 *   This function has no return value (void).
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
