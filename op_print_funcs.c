#include "monty.h"

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void) stack;
	(void) line_number;

	temp = instance->stack;
	while(temp)
		printf("%d\n", temp->n), temp = temp->next;
}

void _pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	
	if (!instance->stack)
		_err(NO_STACK_PINT, NULL);

	printf("%d\n", instance->stack->n);
}
