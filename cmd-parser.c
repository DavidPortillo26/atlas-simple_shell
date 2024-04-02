#include "main.h"

/* Function to split the input into commands into cmds[] */
void split_cmds()
{
    int cnt1; /* Counter variable for commands */

    cnt1 = 1; /* Initialize counter to 1 */
    cmd_exec = strdup(input_buffer); /* Duplicate the input buffer to cmd_exec */

    /* Tokenize the input buffer using semicolons as delimiters */
    cmds[0] = strtok(cmd_exec, ";");
    no_cmds++; /* Increment the number of commands */
    while ((cmds[cnt1] = strtok(NULL, ";")) != NULL)
    {
        cnt1++; /* Increment the counter */
        no_cmds++; /* Increment the number of commands */
    }
    cmds[cnt1] = NULL; /* Set the last element of cmds to NULL to mark the end */
}

/* Function to split the arguments of the command into args[] */
void split_args(char *s)
{
    int cnt2; /* Counter variable for arguments */

    cnt2 = 1; /* Initialize counter to 1 */
    cmd_exec = strdup(s); /* Duplicate the input string to cmd_exec */

    /* Tokenize the input string using whitespace characters (tabs and spaces) as delimiters */
    args[0] = strtok(cmd_exec, "\t ");
    no_args++; /* Increment the number of arguments */
    while ((args[cnt2] = strtok(NULL, "\t ")) != NULL)
    {
        cnt2++; /* Increment the counter */
        no_args++; /* Increment the number of arguments */
    }
    args[cnt2] = NULL; /* Set the last element of args to NULL to mark the end */
}
