#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * cmdline - handles the command line args
 * @prompt: argument that is passed in
 * Return: 
*/
void cmdline(char *prompt)
{
	int argc; /*arg count*/
	char *argv; /*arg list*/
	char modprompt; /*contains a modified prompt*/

	unsigned int jid = 0; /*job id*/

	strcpy(modprompt, prompt);

	if (builtin(char *s)) /*if built-in, execute then return*/
		return;

	jid++ /*assigns a job id*/
}