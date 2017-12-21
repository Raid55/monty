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

void _sub(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!instance->stack || !instance->stack->n)
		_err(NE_NODE_SUB, NULL);

	instance->stack->next->n -= instance->stack->n;
	instance->stack->next->prev = NULL;
	
	free_node();
}

void _div(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!instance->stack || !instance->stack->n)
		_err(NE_NODE_DIV, NULL);

	if (instance->stack->n == 0)
		_err(ZERO_DATA_DIV, NULL);

	instance->stack->next->n /= instance->stack->n;
	instance->stack->next->prev = NULL;

	free_node();
}

void _mul(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!instance->stack || !instance->stack->n)
		_err(NE_NODE_DIV, NULL);

	instance->stack->next->n *= instance->stack->n;
	instance->stack->next->prev = NULL;

	free_node();
}

void _mod(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (!instance->stack || !instance->stack->n)
		_err(NE_NODE_MOD, NULL);

	if (instance->stack->n == 0)
		_err(ZERO_DATA_MOD, NULL);

	instance->stack->next->n %= instance->stack->n;
	instance->stack->next->prev = NULL;

	free_node();
}
