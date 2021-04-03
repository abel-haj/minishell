#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char*	line;

	while (get_next_line(0, &line) >= 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
