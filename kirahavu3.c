#include "simple_shell.h"


	char **km = NULL;
	char *kl = NULL;
	char *kn = NULL;
	int ko = 0;

/**
 * main - The main function for the shell program.
 *
 * @argc: The number of arguments passed to the program.
 * @argv: An array of program arguments to be parsed.
 * This function serves as the entry point to the shell
 * program and performs the following tasks:
 * Applies various functions from the "utils" and "helpers"
 * modules to handle shell operations.
 * Implements the End-of-File (EOF) mechanism for program termination.
 * Prints error messages in case of failures or errors during execution.
 *
 * Return: Returns 0 on successful execution
 * indicating successful program termination.
 */


int main(int argc __attribute__((unused)), char **argv)
{
	char **kaq = NULL;
	int hkj, kar = 0;
	size_t hko = 0;

	signal(SIGINT, kaf);
	kn = argv[0];
	while (1)
	{
		kao();
		kp(" ($) ", STDOUT_FILENO);
		if (getline(&kl, &hko, stdin) == -1)
		{
			free(kl);
			exit(ko);
		}
			kr(kl);
			kag(kl);
			km = kq(kl, ";");

		for (hkj = 0; km[hkj] != NULL; hkj++)
		{
			kaq = kq(km[hkj], " ");
			if (kaq[0] == NULL)
			{
				free(kaq);
				break;
			}
			kar = kah(kaq[0]);

			/* init   */
			kap(kaq, kar);
			free(kaq);
		}
		free(km);
	}
	free(kl);

	return (ko);
}
