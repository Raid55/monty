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
		_err(NO_ARGS, NULL);

	monty_file = fopen(av[1], "r");
	if (!monty_file)
		_err(NO_FILE, av[1]);

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
			_err(INVAL_LINE, op);

		if (err == NEED_ARGS)
		{
			if (int_check(data_n))
				instance->data = atoi(data_n);
			else
				_err(NO_DATA, NULL);
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
