#include "main.h"

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};


	int i = 0;

	while(ops[i].op != NULL && *(ops[i].op) != *s)
	i++;

	if (ops[i].op != NULL && s[1] == '\0')
		return(ops[i].f);

	return (0);
} 
