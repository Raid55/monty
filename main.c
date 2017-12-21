#include "monty.h"

glob_t *instance;

int main(int ac, char **av)
{
	char *op;
	char *data_n;
	size_t line_len = 0;
	int err;
	glob_t tmp = {0, NULL, NULL, NULL, 0};
	instance = &tmp;

	if (ac != 2)
		_err(NO_ARGS, NULL);

	instance->monty_file = fopen(av[1], "r");
	if (!instance->monty_file)
		_err(NO_FILE, av[1]);

	while (getline(&(instance->line), &line_len, instance->monty_file) != -1)
	{
		instance->line_number++;

		op = strtok(instance->line, "\n \t");
		data_n = strtok(NULL, "\n \t");
		
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
	fclose(instance->monty_file);
	free(instance->line);
	while (instance->stack)	
		free_node();
	return(0);
}
