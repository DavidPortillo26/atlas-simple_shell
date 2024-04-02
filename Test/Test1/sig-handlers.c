#include "main.h"

/* Signal handler for SIGINT (Ctrl+C) signal */
void sigintHandler(int sig_num)
{
    /* Re-register the signal handler to handle subsequent SIGINT signals */
    signal(SIGINT, sigintHandler);
    
    /* Flush stdout to ensure any buffered output is written to the console */
    fflush(stdout);
}

/* Signal handler for SIGCHLD (child process termination) signal */
void sigchildHandler(int sig_num)
{
    pid_t cpid; /* Variable to store child process ID */
    int status; /* Variable to store child process status */

    /* Loop until no more terminated child processes are waiting to be reaped */
    while ((cpid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        /* Check if the child process terminated normally */
        if (WIFEXITED(status))
        {
            /* Print a message indicating that the child process exited normally */
            fprintf(stderr, "\n%s with pid %d exited normally\n", args[0], cpid);
        }
    }
    return;
}