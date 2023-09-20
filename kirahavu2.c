#include "simple_shell.h"

/**
 * kao - This function handles non-interactive mode
 * by performing the following tasks:
 *   - [Task 1]: [Describe the first task, if applicable]
 *   - [Task 2]: [Describe the second task, if applicable]
 *   - [Task 3]: [Describe the third task, if applicable]
 *   - [Task N]: [Describe any additional tasks, if applicable]
 *
 * In non-interactive mode
 * explain non-interactive mode means or how it affects function's behavior.
 *
 * Return:
 *   This function does not return a value (void).
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
