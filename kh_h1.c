#include "simple_shell.h"

/**
 *ky - function strchr
 *@kht: string
 *@khd: char
 *
 *Return: char
 */

char *ky(char *kht, char khd)
{
	int i = 0;

	for (; kht[i] != khd && kht[i] != '\0'; i++)
		;
	if (kht[i] == khd)
		return (kht + i);
	else
		return (NULL);
}

/**
 *ku - function strcmp
 *@khgu: 1st
 *@khte: 2nd
 *
 * Return: int
 */

int ku(char *khgu, char *khte)
{
	int khj = 0;

	while (khgu[khj] != '\0')
	{
		if (khgu[khj] != khte[khj])
			break;
		khj++;
	}
	return (khgu[khj] - khte[khj]);
}

/**
 *kw - function strspn
 *@kht2: string 1
 *@kht3: string 2
 *
 *Return: int
 */

int kw(char *kht2, char *kht3)
{
	int khj = 0;
	int khni = 0;

	while (kht2[khj] != '\0')
	{
		if (ky(kht3, kht2[khj]) == NULL)
			break;
		khni++;
		khj++;
	}
	return (khni);
}

/**
 *kx - function strcspn
 *@kht2: string 1
 *@kht3: string 2
 *
 *Return: int
 */


int kx(char *kht2, char *kht3)
{
	int khmo = 0, i;

	for (i = 0; kht2[i] != '\0'; i++)
	{
		if (ky(kht3, kht2[i]) != NULL)
			break;
		khmo++;
	}
	return (khmo);
}

/**
 *kv - function strcat
 *@kheo: destination
 *@khtf:  source
 *
 * Return: char
 */

char *kv(char *kheo, char *khtf)
{
	char *khoh =  NULL;
	int khmu = ks(kheo);
	int khmf = ks(khtf);

	khoh = malloc(sizeof(*khoh) * (khmu + khmf + 1));
	kt(kheo, khoh);
	kt(khtf, khoh + khmu);
	khoh[khmu + khmf] = '\0';
	return (khoh);
}
