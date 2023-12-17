#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * factorize - a func that factorizes a number
 * @line: a pointer to the number
 * Return: int
 */
int factorize(char *line)
{
	u_int32_t num, i;

	num = atoi(line);
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%lld=%ld*%ld\n", num, num / i, i);
			break;
		}
	}
	return (0);
}
/**
 * main - the main function
 * @argc: the number of arguments passed
 * @argv: an array of arguments passed
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t count;
	ssize_t line;
	char *buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buffer, &count, file)) != -1)
		factorize(buffer);
	free(buffer);
	fclose(file);
	return (0);
}

