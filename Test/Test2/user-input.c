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
	pid_t processid;
	int status;
	bool ispiped = false;

	while (1) /*infinite loop*/
	{
		if (isatty(STDIN_FILENO) == 0)
			ispiped = true;
		/*is the data piped into the func or entered via terminal*/

		write(STDOUT_FILENO, "SimpleShell$ ", 13);
		/*prints the prompt onto the terminal*/

		data = getline(&mem, &size, stdin); /*reads the data from stdin*/
	}
}
