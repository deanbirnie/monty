#include <stdio.h>
#include "monty.h"

/**
 * parse_file - Read and parse the Monty byte code file.
 *
 * @filename: Name of the Monty byte code file.
 */
void parse_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	char *line;
	size_t len;
	ssize_t read;
	int i;
	char *opcode, *argument;

	line = NULL;
	len = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		opcode = strtok(line, " \t\n");
		argument = strtok(NULL, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		void (*op_func)(stack_t **, unsigned int) = NULL;

		for (i = 0; i < NUM_OPCODES; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				op_func = opcodes[i].f;
				break;
			}
		}

		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, opcode);
			free(line);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}

		op_func(&stack, line_number);
	}

	free(line);
	free_stack(stack);
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
	const char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];

	parse_file(filename);

	return (EXIT_SUCCESS);
}
