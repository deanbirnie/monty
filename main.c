#include "monty.h"

/**
 * parse_file - Read and parse the Monty byte code file.
 *
 * @filename: Name of the Monty byte code file.
 */
void parse_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		line_number++;
	}

	free(line);
	fclose(file);
}

/**
 * main - entry point of the program
 *
 * @argc: number of arguments in the array
 * @argv: array of arguments
 *
 * Return: exit success or failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	const char *filename = argv[1];

	parse_file(filename);

	return (EXIT_SUCCESS);
}
