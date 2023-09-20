#include "simple_shell.h"

/**
 *kp - function print
 *@khth: string
 *@khtn: stream
 *
 *Return: void
 */
void kp(char *khth, int khtn)
{
	int i = 0;

	for (; khth[i] != '\0'; i++)
		write(khtn, &khth[i], 1);
}

/**
 * kq - function tokenizer
 *@ki_s: input
 *@kh_d: delimiter
 *
 *Return: char
 */

char **kq(char *ki_s, char *kh_d)
{
	int khd = 0;
	char **kbw = NULL;
	char *kuo = NULL;
	char *khtq = NULL;

	kuo = kz(ki_s, kh_d, &khtq);

	while (kuo != NULL)
	{
		kbw = kab(kbw, sizeof(*kbw) * khd, sizeof(*kbw) * (khd + 1));
		kbw[khd] = kuo;
		kuo = kz(NULL, kh_d, &khtq);
		khd++;
	}

	kbw = kab(kbw, sizeof(*kbw) * khd, sizeof(*kbw) * (khd + 1));
	kbw[khd] = NULL;

	return (kbw);
}

/**
 *kt - _strcpy
 *@khtf: source
 *@kheu: dest
 *
 * Return: void
 */

void kt(char *khtf, char *kheu)
{
	int khj = 0;

	for (; khtf[khj] != '\0'; khj++)
		kheu[khj] = khtf[khj];
	kheu[khj] = '\0';
}

/**
 *ks - _strlen
 *@khth: string
 *
 * Return: int
 */

int ks(char *khth)
{
	int khmo = 0;

	if (khth == NULL)
		return (khmo);
	for (; khth[khmo] != '\0'; khmo++)
		;
	return (khmo);
}

/**
 *kr - remove_newline
 *@khts: string
 *
 *
 *Return: void
 */

void kr(char *khts)
{
	int khj = 0;

	while (khts[khj] != '\0')
	{
		if (khts[khj] == '\n')
			break;
		khj++;
	}
	khts[khj] = '\0';
}
