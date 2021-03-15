#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	a[10];
	int	ret;

	ret = 1;
	//a = NULL;
	while (ret > 0)
	{
		ret = read(1, &a, 9);
		printf("%s\n", a);
	}
	return (0);
}
