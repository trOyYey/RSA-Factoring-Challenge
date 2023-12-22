#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void print_factors(long long int n)
{
    if (n % 2 == 0)
    {
        printf("%lld=%lld*%lld\n", n, n / 2, 2LL);
        return;
    }

    long long int i;
    for (i = 3; i <= n / 2; i += 2)
    {
        if (n % i == 0)
        {
            printf("%lld=%lld*%lld\n", n, n / i, i);
            return;
        }
    }
}

int main(int argc, char **argv)
{
	char *buffer = NULL;
	FILE *fd;
	size_t l = 0;
	ssize_t stat;
	long long int number;

	if (argc != 2)
		return EXIT_FAILURE;

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return EXIT_FAILURE;

	while ((stat = getline(&buffer, &l, fd)) != -1)
	{
		if (stat > 0 && buffer[stat - 1] == '\n')
			buffer[stat - 1] = '\0';

		// Skip empty lines
		if (strlen(buffer) == 0)
		{
		continue;
		}

		// Skip non-numeric lines
		char *endptr;
		number = strtoll(buffer, &endptr, 10);
		if (endptr == buffer || *endptr != '\0')
        		{
			printf("Skipping non-numeric line: %s\n", buffer);
			continue;
			}
        	print_factors(number);
	}
	fclose(fd);
	free(buffer);
	return EXIT_SUCCESS;
}
