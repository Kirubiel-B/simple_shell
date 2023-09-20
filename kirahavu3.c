#include "simple_shell.h"


	char **km = NULL;
	char *kl = NULL;
	char *kn = NULL;
	int ko = 0;

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 *
 * applies the functions in utils and helpers
 * implements EOF
 * Prints error on Failure
 * Return: 0 on success
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
