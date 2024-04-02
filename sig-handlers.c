#include "main.h"

/* Signal handler function for SIGCHLD (child process terminated) */
/* This function is declared as static to limit its scope to the current source file */
static void sigchildHandler(int sig_num)
{
    pid_t cpid; /* Variable to store child process ID */
    int status; /* Variable to store exit status of child process */

    /* Loop until no child process is left */
    while ((cpid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        /* Check if the child process terminated normally */
        if (WIFEXITED(status))
        {
            /* Print a message indicating the name and PID of the exited process */
            fprintf(stderr, "\n%s with pid %d exited normally\n", args[0], cpid);
        }
    }
    return; /* Exit the signal handler function */
}

/* Signal handler function for SIGINT (Ctrl+C) */
void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler); /* Reset the signal handler to itself */
    fflush(stdout); /* Flush the standard output buffer to ensure all output is displayed */
}
