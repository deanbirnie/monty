#include "monty.h"

/**
 * opcode_push - pushes an element to the stack
 *
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode being executed
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, " \t\n");

	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	int value = atoi(argument);

	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * opcode_pall - prints all the values on the stack starting at the top
 *
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode being executed
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
