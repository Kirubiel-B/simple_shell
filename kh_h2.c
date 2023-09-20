#include "simple_shell.h"

/**
 * kaf - function control c hundler
 * @khtn: signumber
 *
 * Return: void
 */
void kaf(int khtn)
{
	if (khtn == SIGINT)
		kp("\n($) ", STDIN_FILENO);
}

/**
 * kag - function removes comments
 * @khju: input
 *
 * Return: void
 */
void kag(char *khju)
{
	int khj = 0;

	if (khju[khj] == '#')
		khju[khj] = '\0';
	while (khju[khj] != '\0')
	{
		if (khju[khj] == '#' && khju[khj - 1] == ' ')
			break;
		khj++;
	}
	khju[khj] = '\0';
}

/**
 *kz - function strtok
 *@khth: string
 *@khen: delim
 *@khts: save pointer
 *
 *Return: char
 */
char *kz(char *khth, char *khen, char **khts)
{
	char *khgi;

	if (khth == NULL)
		khth = *khts;

	if (*khth == '\0')
	{
		*khts = khth;
		return (NULL);
	}

	khth += kw(khth, khen);
	if (*khth == '\0')
	{
		*khts = khth;
		return (NULL);
	}

	khgi = khth + kx(khth, khen);
	if (*khgi == '\0')
	{
		*khts = khgi;
		return (khth);
	}

	*khgi = '\0';
	*khts = khgi + 1;
	return (khth);
}


/**
 * kab - function realloc
 * @kac: pointer
 * @kad: old size
 * @kae: new size
 *
 * Return: void
 */
void *kab(void *kac, unsigned int kad, unsigned int kae)
{
	void *khul;
	unsigned int khj;

	if (kac == NULL)
	{
		khul = malloc(kae);
		return (khul);
	}
	else if (kae == kad)
		return (kac);
	else if (kae == 0 && kac != NULL)
	{
		free(kac);
		return (NULL);
	}
	else
	{
		khul = malloc(kae);
		if (khul != NULL)
		{
			for (khj = 0; khj < min(kad, kae); khj++)
				*((char *)khul + khj) = *((char *)kac + khj);
			free(kac);
			return (khul);
		}
		else
			return (NULL);

	}
}

/**
 * kaa - function atoi
 * @kht: char s
 *
 * Return: int
 */
int kaa(char *kht)
{
	unsigned int kho = 0;

	do {
		if (*kht == '-')
			return (-1);
		else if ((*kht < '0' || *kht > '9') && *kht != '\0')
			return (-1);
		else if (*kht >= '0'  && *kht <= '9')
			kho = (kho * 10) + (*kht - '0');
		else if (kho > 0)
			break;
	} while (*kht++);
	return (kho);
}
