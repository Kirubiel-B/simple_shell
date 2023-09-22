#include "simple_shell.h"
/**
 * kah - Adjudicates the syntactical category of the input command.
 * @command: The command string subjected to parsing and classification.
 * This function conducts a comprehensive analysis of the provided command
 * categorizing it into a specific syntactical class.
 * It subsequently returns a constant signifying the discerned class.
 * Return: constant denoting ascertained syntactical classification of command.
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
 * kai - Orchestrates execution of command contingent determined type.
 * @tokenized_command: command represented in tokenized form
 * @command_type: The categorization denoting the type of the command.
 * This function serves as the central controller
 * coordinating execution of a command based syntactical classification.
 * takes tokenized representation of command and command's type as inputs,
 * proceeds to execute the command according to its designated category.
 * Return: No explicit return;
 * this function operates to execute the command.
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
 * kaj - Determines the presence and location of a specified command
 * within the system's PATH environment.
 * @command: The command for which presence within the PATH is being verified.
 * This function is responsible for conducting a comprehensive search
 * within the system's PATH environment to ascertain the existence
 * and location of the specified command. Upon completion
 * it returns the absolute path where the command is found
 * or NULL if it is not present within the PATH.
 * Return: A string containing the absolute path of the located command,
 * or NULL if not found.
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
 * kak - Looks up and returns funct pointer based on given command.
 * @command: The command string to match in a predefined mapping.
 * This function searches for the corresponding function
 * in a predefined mapping based on the provided command.
 * If a match is found, it returns a pointer to that function;
 * otherwise, it returns NULL.
 * Return: A pointer to the matched function.
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
 * kal - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 * This function retrieves the value of
 * the specified environment variable and returns it as a string.
 * If the variable does not exist or an error occurs,
 * this function returns NULL.
 * Return: The value of the variable as a string (or N on failure).
 */
char *kal(char *name)
{
	char **my_environ;
	char *pair_ptr;
	char *name_cpy;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
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
