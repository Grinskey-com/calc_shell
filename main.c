#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	int num1, num2, op, i;	
	char *token_arr[1024];
	int n; 

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
			op = atoi(token_arr[1]);
			num2 = atoi(token_arr[2]);
			printf("num1:%d op:%d num2:%d\n",num1 ,op ,num2); 
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


