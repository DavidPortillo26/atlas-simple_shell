#include "main.h"

// Function to split the input into commands into cmds[]
void split_cmds()
{
    int cnt1; // Counter variable for commands

    cnt1 = 1; // Initialize counter to 1
    cmd_exec = strdup(input_buffer); // Duplicate the input buffer to cmd_exec

    // Tokenize the input buffer using semicolons as delimiters
    cmds[0] = strtok(cmd_exec, ";");
    no_cmds++; // Increment the number of commands
    while ((cmds[cnt1] = strtok(NULL, ";")) != NULL)
    {
        cnt1++; // Increment the counter
        no_cmds++; // Increment the number of commands
    }
    cmds[cnt1] = NULL; // Set the last element of cmds to NULL to mark the end
}