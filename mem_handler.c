#include "mont_pyt.h"

stack_t *alloc_node(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	return (new);
}

/* void free_stack(void) */
/* { */
/* 	stack_t *next; */

/* 	if (instance->stack) */
/* 		return; */
/* 	printf("lo."); */
/* 	while (instance->stack) */
/* 	{ */
/* 		next = instance->stack->next; */
/* 		free(instance->stack); */
/* 		instance->stack = next; */
/* 	} */

/* 	instance->stack = NULL; */
/* } */

void free_node(void)
{
	stack_t *tmp;

	tmp = instance->stack;
	if (instance->stack->next == NULL)
		instance->stack = NULL;
	else
	{
		instance->stack = instance->stack->next;
		instance->stack->prev = NULL;
	}
	
	free(tmp);
}
