#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while(1)
	{
		printf(">>> ");
		read = getline(&line, &len, stdin);

		if (read != -1)
			printf("you entered: %s\n", line);
		else
		{
			printf("something went wrong, please try again\n");
			break;
		}
	}
	free(line);
	return(0);
}
