#include "main.h"

/* Function to perform ls */
void ls_command()
{
    struct dirent **filelist; /* Pointer to an array of directory entries */
    int n; /* Number of directory entries */
    int i; /* Loop counter */

    /* Scans the current directory and stores directory entries in filelist */
    n = scandir(".", &filelist, NULL, alphasort);
    for (i = 0; i < n; i++)
    {
        /* Filters out hidden files (files starting with dot) */
        if ((filelist[i]->d_name)[0] != '.')
        {
            printf("%s\n", filelist[i]->d_name); /* Prints the name of the file/directory*/
        }
        free(filelist[i]); /* Frees memory allocated for each directory entry */
    }
    free(filelist); /* Frees memory allocated for the array of directory entries */
}

// Function to perform ls -a
void lsa_command()
{
    struct dirent **filelist; // Pointer to an array of directory entries
    int n; // Number of directory entries
    int i; // Loop counter

    // Scans the current directory and stores directory entries in filelist
    n = scandir(".", &filelist, NULL, alphasort);
    for (i = 0; i < n; i++)
    {
        printf("%s\n", filelist[i]->d_name); // Prints the name of the file/directory
        free(filelist[i]); // Frees memory allocated for each directory entry
    }
    free(filelist); // Frees memory allocated for the array of directory entries
}