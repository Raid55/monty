#include "monty.h"

void _pall(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	stack_t *tmp;

	tmp = instance->stack;
	while(tmp)
		printf("%d\n", tmp->n), tmp = tmp->next;
}

void _pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	printf("%d\n", instance->stack->n);
}
