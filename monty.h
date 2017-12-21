#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct glob_var
{
	int data;
	FILE *monty_file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
} glob_t;

extern glob_t *instance;

/*function prototypes*/
void _add(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void run_op_func(char *op_str);
int check_for_op(char *opcode);
int int_check(char *data_n);
stack_t *alloc_node(void);
void free_node(void);
void _err(int, char *);
/* void free_stack(void); */

/*cheker for func stuff*/
#define NEED_ARGS 2
#define NO_ARGS 1
#define NULL_FUNC 0
#define SKIP_LINE 3
/*err codes*/
#define NO_ARGS       1
#define NO_FILE       2
#define NO_DATA       3
#define NO_STACK_PINT 4
#define NO_STACK_POP  5
#define NE_NODE_SWAP  6
#define NE_NODE_ADD   7
#define INVAL_LINE    8
#define MALLOC_ERR    9


#endif
