#include "main.h"
/**
 * main - reads the user input
 * Return: success
*/
int main(void)
{
	char *mem = NULL; /*data from standard input*/
	size_t size = 0; /*size of mem from the standard input*/
	ssize_t data;
	pid_t childpid = fork(); /*creates a c_pid to execute a command*/
	int status;
	bool ispiped = false; /*used to check if argument is piped*/
	struct stat statbuf;

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

		if (builtin(char *s)) /*if built-in, execute then return*/
			return;

		if (childpid == -1) /*checks if child process failed*/
		{
			perror("Error fork()");
			exit(EXIT_FAILURE);
		}

		if (childpid == 0)
		{
			exec
		}
	}

	free(mem); /*once func is finished free the memory*/
	return (0); /*return 0*/
}
