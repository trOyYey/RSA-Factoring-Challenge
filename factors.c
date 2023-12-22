#include <stdlib.h>
#include <stdio.h>


void print_factors(long long int n)
{
	long long int ix;
	if (n % 2 == 0)
	{
		printf("%lld=%lld*%d\n", n, n / 2, 2);
		return;
	}

	for (x = 3; x <= n / 2; x += 2)
	{
		if (n % i == 0)
		{
			printf("%lld=%lld*%lld\n", n, n / x, x);
			break;
		}
	}
}

int main(int argc, char **argv)
{
	char *buffer = NULL;
	FILE *fd;
	size_t lenght = 0;
	ssize_t status;
	long long int num;
	if (argc != 2)
		return (EXIT_FAILURE);

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (EXIT_FAILURE);
	status = getline(&buffer, &lenght, fd);

	while (status != -1)
	{
		num = atoll(buffer);
		free(buffer);
		buffer = NULL;
		lenght = 0;
		print_factors(numb);
		status = getline(&buffer, &lenght, fd);
	}
	fclose(fd);
	return (EXIT_SUCCESS);

}
