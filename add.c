#include "monty.h"

/**
 * opcode_add - adds the top two elements of the stack
 *
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode being executed
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	(*stack)->next->n = a + b;

	top = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(top);
}
