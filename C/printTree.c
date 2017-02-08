/* 
   Thao Nguyen
   CWID: 890848781
   CPSC 351 - Assignment 3
   ***Program that prints out the directory tree 
   of the specified directory***
   November 10, 2016
*/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define KGRN "\x1B[32m"
#define KNRM  "\x1B[0m"

void printTree(char *dir, int depth, int *numDir, int *numFile)
{
    DIR *root;
    struct dirent *entry;
    struct stat buf;
    int spaces = (depth * 4);

    // Check if the directory exists, or can be openned
    if((root = opendir(dir)) == NULL) 
    {
	// Error message and return if directory does not exist
        fprintf(stderr, "Cannot open directory: %s\n", dir);
        return;
    }
    
    // Change working directory to the specified directory
    chdir(dir);

    // While entries returned by readdir exist
    while((entry = readdir(root)) != NULL) 
    {
        lstat(entry->d_name, &buf);

	// Check whether the entry is a directory
        if(S_ISDIR(buf.st_mode)) 
        {
            // Found a directory, but ignore . and ..
            if(strcmp(".", entry->d_name) == 0 || 
               strcmp("..", entry->d_name) == 0)
                continue;
	    
	    // Print out the directory name
            printf("%*s%s\n", spaces, "|_", entry->d_name);

	    // Increment the number of directories traversed
	    (*numDir)++;

            // Recursively call printTree until there's no more subdirectories
            printTree(entry->d_name, depth + 1, numDir, numFile);    
        }
        else 	// Entry is not a directory --> is a file
        {
	    // Print out file name in green text color
	    printf("%*s", spaces, "|_");
	    printf(KGRN "%s\n", entry->d_name);

	    // Change text color back to normal
            printf(KNRM);   

	    // Increment the number of files traversed
	    (*numFile)++;
        }
    }
    
    // No more subdirectories to process, return to parent directory
    chdir("..");
    closedir(root);
}

int main(int argc, char* argv[])
{
    int numDir = 0; 		// Number of directories traversed
    int *ptrDir = &numDir;      // Pointer to numDir
    int numFile = 0;            // Number of files traversed
    int *ptrFile = &numFile;    // Pointer to numFile
    char *topDir;		// Start directory
    
    // If no directory is specified, use
    // current working directory as start directory
    if (argc != 2)	
        topDir = ".";
    // Otherwise, use the specified directory
    else
        topDir = argv[1];

    // Print the directory tree
    printf("%s\n", topDir);
    printTree(topDir, 0, ptrDir, ptrFile);
    
    // Print total number of directories and files
    printf("\nTotal number of directories: %d", numDir);
    printf(", number of files: %d\n", numFile);

    return 0;
}
