#include "simple_shell.h"

/**
 * kao - handles non_interactive mode
 *
 * Return: void
 */

void kao(void)
{
	char **kaq = NULL;
	int hkj, kar = 0;
	size_t hko = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&kl, &hko, stdin) != -1)
		{
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
				kap(kaq, kar);
				free(kaq);
			}
			free(km);
		}
		free(kl);
		exit(ko);
	}
}
