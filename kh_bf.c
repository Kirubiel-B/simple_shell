#include "simple_shell.h"

/**
 * kan - function quit
 * @kha: command
 *
 * Return: void
 */

void kan(char **kha)
{
	int k1 = 0, k2;

	for (; kha[k1] != NULL; k1++)
		;
	if (k1 == 1)
	{
		free(kha);
		free(kl);
		free(km);
		exit(ko);
	}
	else if (k1 == 2)
	{
		k2 = kaa(kha[1]);
		if (k2 == -1)
		{
			kp(kn, STDERR_FILENO);
			kp(": 1: exit: Illegal number: ", STDERR_FILENO);
			kp(kha[1], STDERR_FILENO);
			kp("\n", STDERR_FILENO);
			ko = 2;
		}
		else
		{
			free(kl);
			free(kha);
			free(km);
			exit(k2);
		}
	}
	else
		kp("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}


/**
 *kam - function env
 *@kha: command
 *
 *Return: void
 */

void kam(char **kha __attribute__((unused)))
{
	char **kj = NULL;
	int k;

	for (k = 0; kj[k] != NULL; k++)
	{
		kp(kj[k], STDOUT_FILENO);
		kp("\n", STDOUT_FILENO);
	}
}

