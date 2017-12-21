#include "monty.h"

void _add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	instance->stack->next->n += instance->stack->n;
	
	free_node();
}
