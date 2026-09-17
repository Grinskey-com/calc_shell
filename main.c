#include "main.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int (*get_op_func(char *s))(int, int);

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	int num1, num2, i;	
	char *token_arr[1024];
	int n;
	int (*func)(int, int);
	char *op;

	while(1)
	{
		printf(">>> ");
		read = getline(&line, &len, stdin);

		if (read != -1)
		{
			token = strtok(line, " ");

			while (token != NULL)
			{	
				token_arr[i] = token;
				i++;
				token = strtok(NULL, " ");
			}

			num1 = atoi(token_arr[0]);
			op = token_arr[1];
			num2 = atoi(token_arr[2]);
		//	printf("num1:%d op:%s num2:%d\n",num1 ,op ,num2);

			func = get_op_func(op);

			if (func == NULL)
			{
				printf("ERROR\n");
				exit(1);
			}

			printf("%d\n", func(num1, num2));

		}
		else
		{
			printf("ERROR\n");
			free(line);
			break;
		}
	}
	free(line);
	return(0);
}


