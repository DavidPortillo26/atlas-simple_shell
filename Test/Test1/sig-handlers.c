#include "main.h"

/* Signal handler for SIGINT (Ctrl+C) signal */
void sigintHandler(int sig_num)
{
    /* Re-register the signal handler to handle subsequent SIGINT signals */
    signal(SIGINT, sigintHandler);
    
    /* Flush stdout to ensure any buffered output is written to the console */
    fflush(stdout);
}