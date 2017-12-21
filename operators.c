#include "monty.h"

void run_op_func(char *op_str)
{
	stack_t **lol = NULL;
	int i = 0;
	instruction_t opparr[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pchar", _pchar},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"nop", _nop},
		{"#", _nop},
		{NULL, NULL}
	};

	while (opparr[i].opcode != NULL)
	{
		if (strcmp(op_str, opparr[i].opcode) == 0)
			opparr[i].f(lol, instance->line_number);
		i++;
	}
}

int check_for_op(char *opcode)
{
	int i = 0;

	instruction_t opparr[] = {
		{"push", NULL},
		{"pall", NULL},
		{"pint", NULL},
		{"pchar", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"sub", NULL},
		{"div", NULL},
		{"mul", NULL},
		{"mod", NULL},
		{"nop", NULL},
		{"#", NULL},
		{NULL, NULL}
	};

	while (opparr[i].opcode != NULL)
	{
		if (strcmp(opcode, opparr[i].opcode) == 0)
		{
			if (strcmp(opcode, opparr[0].opcode) == 0)
				return (NEED_ARGS);
			else
				return (NO_ARGS);
		}
		i++;
	}
	return (NULL_FUNC);
}

int int_check(char *data_n)
{
	int i = 0;

	if (!data_n)
		return (0);
	while (data_n[i])
	{
		if (isdigit(data_n[i]) == 0 &&  data_n[i] != '-')
			return (0);
		else
			i++;
	}
	return (1);
}
