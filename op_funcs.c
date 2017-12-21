#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	(void) line_number;
	(void) stack;
	
	new_node = alloc_node();

	new_node->n = instance->data;
	new_node->prev = NULL;

	if (instance->stack == NULL)
	{
		new_node->next = NULL;
		instance->stack = new_node;
	}
	else
	{
		new_node->next = instance->stack;
		instance->stack->prev = new_node;
		instance->stack = new_node;
	}
}

void _pop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	
	if (!instance->stack)
		_err(NO_STACK_POP, NULL);

	free_node();

}

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void) stack;
	(void) line_number;
	
	if (!instance->stack && !instance->stack->next)
		_err(NE_NODE_SWAP, NULL);
	temp = instance->stack->next;

	instance->stack->next = temp->next;
	instance->stack->prev = temp;

	temp->next = instance->stack;
	temp->prev = NULL;

	instance->stack = temp;
}

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	/*do a barel roll*/
}
