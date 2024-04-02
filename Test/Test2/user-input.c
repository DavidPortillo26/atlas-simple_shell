#include "main.h"
/**
 * main - reads the user input
 * Return: success
*/
int main(int argc, char **argv, char **env)
{
	char *mem = NULL; /*data from standard input*/
	char *path; /*stores the result of the getPATH function*/
	char **args; /*stores the result of the split string function*/
	size_t size = 0; /*size of mem from the standard input*/
	ssize_t data; /*stores data from the getiline function*/
	pid_t childpid = fork(); /*creates a c_pid to execute a command*/
	int status; /*status*/
	bool ispiped = false; /*used to check if argument is piped*/

	while (1 && !ispiped) /*infinite loop but if piped then only run once */
	{
		if (isatty(STDIN_FILENO) == 0)
			ispiped = true;
		/*is the data piped into the func or entered via terminal*/

		write(STDOUT_FILENO, "SimpleShell$ ", 13);
		/*prints the prompt onto the terminal*/

		data = getline(&mem, &size, stdin); /*reads the data from stdin*/

		if (data == -1)
		{
			perror("Error getline()");
			free(mem); /*free memory if it fails*/
			exit(EXIT_FAILURE);
		}

		if (builtin(data)) /*if built-in, execute then return*/
			return;
											/*spst is short for splitstring*/
		args = splitstring(mem, " \t\n") /*passes mem and " \t\n" into spst*/

		if (strcmp(args[0], "exit") == 0) /*check if the first arg is exit*/
			exit(0);

		if (childpid == 0) /*attempt to execute a command if childpid == 0*/
		{
			path = getPATH(args[0]);

			if (path) /*if full path is returned execute*/
				execve(path, args, env);
			else /*if childpid != 0 print command not found*/
				printf("Command not found\n");
			exit(0);
		}
		else /*if not a childpid then wait for childpid to finish*/
			wait(&status);
	}

	free(mem); /*once func is finished free the memory*/
	return (0); /*return 0*/
}
