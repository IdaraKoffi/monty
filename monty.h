#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - a doubly linked list representation of a stack or queue
 * @n: an integer
 * @prev: It points to the previous element of the stack or queue
 * @next: It points to the next element of a stack or queue
 *
 * Description: A doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */
	typedef struct stack_s
	{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
	} stack_t;

/**
 * struct globals - The global structure to use in the functions
 * @lifo: stack or queue
 * @cont: current line
 * @arg: The second parameter inside the current line
 * @head: doubly lined list
 * @fd: a file descriptor
 * @buffer: Input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: The opcode
 * @f: function to handle the opcode
 * 
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

	extern global_t vglo;

	/* opcode_instructions */
	void _push(stack_t **stack, unsigned int line_number);
	void _pall(stack_t **stack, unsigned int line_number);
	void _pint(stack_t **doubly, unsigned int cline);
	void _pop(stack_t **doubly, unsigned int cline);
	void _swap(stack_t **doubly, unsigned int cline);
	void _queue(stack_t **doubly, unsigned int cline);
	void _stack(stack_t **doubly, unsigned int cline);
	void _add(stack_t **doubly, unsigned int cline);
	void _nop(stack_t **doubly, unsigned int cline);
	void _sub(stack_t **doubly, unsigned int cline);
	void _div(stack_t **doubly, unsigned int cline);
	void _mul(stack_t **doubly, unsigned int cline);
	void _mod(stack_t **doubly, unsigned int cline);
	void _pchar(stack_t **doubly, unsigned int cline);
	void _pstr(stack_t **doubly, unsigned int cline);
	void _rotl(stack_t **doubly, unsigned int cline);
	void _rotr(stack_t **doubly, unsigned int cline);

	/* get function */
	void (*getOpcodes(char *opc))(stack_t **stack, unsigned int line_number);

	/* imported function */
	int _sch(char *s, char c);
	char *_strtoky(char *s, char *d);
	void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
	void *_calloc(unsigned int nmemb, unsigned int size);
	int _strcmp(char *s1, char *s2);

	/* doubly linked list functions */
	stack_t *add_dnodeint_end(stack_t **head, const int n);
	stack_t *add_dnodeint(stack_t **head, const int n);
	void free_dlistint(stack_t *head);

	/* main */
	void free_vglo(void);

	#endif
