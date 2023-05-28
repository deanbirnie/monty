#include "monty.h"

/**
 * opcode_nop - does nothing
 *
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode being executed
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
