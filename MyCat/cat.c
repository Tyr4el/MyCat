#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // #define buffer size

int main(int argc, char **argv)
{
	char *fname = argv[1]; // 1st command line argument is the file name

	if (argc < 2) // If the argument count is less than 2, then the user did not enter a file name
	{
		perror("Expected filename.");
		return 5; // I/O Error
	}

	FILE *file = fopen(fname, "r"); // OPEN the file

	char string[BUFFER_SIZE]; // Set array to size BUFFER_SIZE

	if (file == NULL) // If file doesn't exist...or something went wrong.
	{
		perror("Error: ");
		return 2; // No such file or directory
	}
	else
	{
		// Start looping through each line of the file until reaching NULL (the end)
		while (fgets(string, BUFFER_SIZE, file) != NULL) 
		{
			printf("%s", string);
		}

		printf("\n"); // Print that last neat line
	}

	free(string); // Free and close all the things
	fclose(file);

	return 0; // All done!
}

