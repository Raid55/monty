#include "monty.h"

glob_t *instance;

int main(int ac, char **av)
{
	char *op;
	char *data_n;
	size_t line_len = 0;
	FILE *monty_file;
	char *line = NULL;
	int err;
	glob_t tmp = {0, NULL, 0};
	instance = &tmp;

	if (ac != 2)
	{
		printf("USAGE is lik tis");
		exit(EXIT_FAILURE);
		/* _err(NO_ARG); */
	}

	monty_file = fopen(av[1], "r");
	if (!monty_file)
	{
		printf("NU files");
		exit(EXIT_FAILURE);
		/* _err(NO_FILE); */
	}

	while (getline(&line, &line_len, monty_file) != -1)
	{
		instance->line_number++;

		op = strtok(line, " \n\t");
		data_n = strtok(NULL, " \n\t");
		
		/* printf("op[%s]dat[%s]\n", op, data_n); */
		if (op == NULL)
			err = SKIP_LINE;
		else
			err = check_for_op(op);
		if (err == NULL_FUNC)
		{
			printf("inval line");
			exit(EXIT_FAILURE);
			/* _err(INVAL_LINE); */
		}

		if (err == NEED_ARGS)
		{
			if (int_check(data_n))
				instance->data = atoi(data_n);
			else
			{
				printf("invalidante lines");
				exit(EXIT_FAILURE);
			}
		}
		if (err != SKIP_LINE)
			run_op_func(op);
	}
	fclose(monty_file);
	free(line);
	while (instance->stack)	
		free_node();
	return(0);
}
