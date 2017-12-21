#include "mont_pyt.h"

void _push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	stack_t *new;
	
	new = malloc(sizeof(stack_t));

	if (new == NULL)
		printf("alloc err"), exit(EXIT_FAILURE);

	new->n = instance->data;
	new->prev = NULL;

	if (instance->stack == NULL)
	{
		new->next = NULL;
		instance->stack = new;
	}
	else
	{
		new->next = instance->stack;
		instance->stack->prev = new;
		instance->stack = new;
	}
}

void _pop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	free_node();

}

void _swap(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	stack_t *tmp;
	
	tmp = instance->stack->next;

	instance->stack->next = tmp->next;
	instance->stack->prev = tmp;

	tmp->next = instance->stack;
	tmp->prev = NULL;

	instance->stack = tmp;
}

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	//do a barel roll
	int a = 1;
	int b = 2;
	int c = 0;
	int d = 0;
	
	if (a == b + 1)
		b = 3;
	c = 3;
	d += c + b + 1;
}

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
