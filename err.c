#include "monty.h"

void _err(int errcode, char *info)
{
	(void) info;
	
	switch(errcode)
	{
		case NO_ARGS:
			printf("USAGE: monty file");
			break;
		case NO_FILE:
			printf("Error: Can't open file %s", info);
			break;
		case NO_DATA:
			printf("L%d: usage: push integer", instance->line_number);
			break;
		case INVAL_LINE:
			printf("L%d: unknown instruction %s", instance->line_number, info);
			break;
		case MALLOC_ERR:
			printf("Error: malloc failed");
			break;
		default:
			printf("U WUT M8???");
	}
	exit(EXIT_FAILURE);
}
