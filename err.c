#include "monty.h"

void _err(int errcode, char *info)
{
	(void) info;
	
	switch(errcode)
	{
		case NO_ARGS:
			printf("USAGE: monty file\n");
			break;
		case NO_FILE:
			printf("Error: Can't open file %s\n", info);
			break;
		case NO_DATA:
			printf("L%d: usage: push integer\n", instance->line_number);
			break;
		case NO_STACK_PINT:
			printf("L%d: can't pint, stack empty\n", instance->line_number);
			break;
		case NO_STACK_POP:
			printf("L%d: can't pop an empty stack\n", instance->line_number);
			break;
		case NE_NODE_SWAP:
			printf("L%d: can't pop an empty stack\n", instance->line_number);
			break;
		case NE_NODE_ADD:
			printf("L%d: can't add, stack too short\n", instance->line_number);
			break;
		case INVAL_LINE:
			printf("L%d: unknown instruction %s\n", instance->line_number, info);
			break;
		case MALLOC_ERR:
			printf("Error: malloc failed\n");
			break;
		default:
			printf("U WUT M8???\n");
	}
	if (instance->monty_file)
		fclose(instance->monty_file);
	if (instance->line)
		free(instance->line);
	while (instance->stack)	
		free_node();
	exit(EXIT_FAILURE);
}
