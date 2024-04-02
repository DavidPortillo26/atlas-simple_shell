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
// Function to perform ls -l
void lsl_command()
{
    DIR *dir; // Pointer to a directory stream
    struct dirent *file; // Pointer to a directory entry
    struct stat sbuf; // Structure to store file/directory attributes
    char buf[128]; // Buffer for username and groupname
    struct passwd pwent, *pwentp; // Structure to store user information
    struct group grp, *grpt; // Structure to store group information
    char datestring[256]; // Buffer for formatted date and time
    struct tm time; // Structure to store broken-down time
    char perms[11]; // Buffer for file permissions
    char *path = NULL; // Buffer for the current working directory

// Get the current working directory
    getcwd(path, sizeof(path));

    // Open the current directory
    dir = opendir(path);

    // Iterate through each file/directory in the directory
    while (file = readdir(dir))
    {
        // Exclude hidden files (files starting with dot)
        if ((file->d_name)[0] != '.')
        {
            // Get file/directory attributes
            stat(file->d_name, &sbuf);

            // Determine file permissions
            // Populate perms array accordingly
            // Note: Permissions may vary based on file type (regular file, directory, etc.)
            // and user/group permissions (read, write, execute)
            // Print permissions, number of links, username, groupname, file size, last modified date/time, and filename
        }
    }
}