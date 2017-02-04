#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

int main(int argc, char **argv)
{
	char *fname = argv[1]; // 1st command line argument is the file name

	if (argc > 1)
	{
		perror("Expected filename.");
		return 5;
	}

	FILE *file = fopen(fname, "r");

	char *string = malloc(sizeof(char) * BUFFER);

	if (file == NULL) // If file doesn't exist...or something went wrong.
	{
		perror("Error: ");
		return 2; // No such file or directory
	}
	else
	{
		while (fgets(string, BUFFER, file) != NULL)
		{
			printf("%s", string);
		}

		printf("\n"); // Print that last neat line
	}

	free(string); // Free and close all the things
	fclose(file);

	return 0;
}

