#include "simple_shell.h"

/** kah - determines the type of the command
 * @command: command to be parsed
 *
 * Return: constant representing the type of the command
 * Description -
 * 		 EXTERNAL_COMMAND (1) represents commands like /bin/ls
 *		 INTERNAL_COMMAND (2) represents commands like exit, env
 *		 PATH_COMMAND (3) represents commands found in the PATH like ls
 *		 INVALID_COMMAND (-1) represents invalid commands
 */

int kah(char *command)
{
	int hkj;
	char *internal_command[] = {"env", "exit", NULL};
	char *path = NULL;

	for (hkj = 0; command[hkj] != '\0'; hkj++)
	{
		if (command[hkj] == '/')
			return (KA);
	}
	for (hkj = 0; internal_command[hkj] != NULL; hkj++)
	{
		if (ku(command, internal_command[hkj]) == 0)
			return (KB);
	}
	/* @kaj - checks if a command is found in the PATH */
	path = kaj(command);
	if (path != NULL)
	{
		free(path);
		return (KC);
	}

	return (KD);
}

/**
 * kai - executes a command based on it's type
 * @tokenized_command: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @command_type: type of the command
 *
 * Return: void
 */
void kai(char **tokenized_command, int command_type)
{
	void (*kg)(char **kh);

	if (command_type == KA)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(kal("PWD"));
			exit(2);
		}
	}
	if (command_type == KC)
	{
		if (execve(kaj(tokenized_command[0]), tokenized_command, NULL) == -1)
		{
			perror(kal("PWD"));
			exit(2);
		}
	}
	if (command_type == KB)
	{
		kg = kak(tokenized_command[0]);
		kg(tokenized_command);
	}
	if (command_type == KD)
	{
		kp(kn, STDERR_FILENO);
		kp(": 1: ", STDERR_FILENO);
		kp(tokenized_command[0], STDERR_FILENO);
		kp(": not found\n", STDERR_FILENO);
		ko = 127;
	}
}

/**
 * kaj - checks if a command is found in the PATH
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */
char *kaj(char *command)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = kal("PATH");
	int i;

	if (path == NULL || ks(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (ks(path) + 1));
	kt(path, path_cpy);
	path_array = kq(path_cpy, ":");
	for (i = 0; path_array[i] != NULL; i++)
	{
		temp2 = kv(path_array[i], "/");
		temp = kv(temp2, command);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(path_array);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(path_array);
	return (NULL);
}

/**
 * kak - retrieves a function based on the command given and a mapping
 * @command: string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*kak(char *command))(char **)
{
	int hkj;
	ki mapping[] = {
		{"env", kam}, {"exit", kan}
	};

	for (hkj = 0; hkj < 2; hkj++)
	{
		if (ku(command, mapping[hkj].kf) == 0)
			return (mapping[hkj].kg);
	}
	return (NULL);
}

/**
 * kal - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *kal(char *name)
{
	char **my_environ;
	char *pair_ptr;
	char *name_cpy;

	for (my_environ = kj; *my_environ != NULL; my_environ++)
	{
		for (pair_ptr = *my_environ, name_cpy = name;
		     *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*name_cpy == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);
}
