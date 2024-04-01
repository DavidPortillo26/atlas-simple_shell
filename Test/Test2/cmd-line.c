#include "main.h"
/**
 * cmdline - handles the command line args
 * @prompt: argument that is passed in
 * Return: Success
*/
void cmdline(char *prompt)
{
	int argc; /*arg count*/
	char *argv; /*arg list*/
	char modprompt; /*contains a modified prompt*/
	int background; /*used to wait for foreground process to end*/
	pid_t childpid = fork();

	unsigned int jid = 0; /*job id*/

	strcpy(modprompt, prompt);

	if (builtin(char *s)) /*if built-in, execute then return*/
		return;

	jid++ /*assigns a job id*/

	if (childpid == 0) /*child process*/
	{

	}
}
