#include "monty.h"

void _add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	
	if (!instance->stack || !instance->stack->next)
		_err(NE_NODE_ADD, NULL);


	instance->stack->next->n += instance->stack->n;
	instance->stack->next->prev = NULL;
	free_node();
}
