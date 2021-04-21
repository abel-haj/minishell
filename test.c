#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	char	a[10];
	int	ret;

	ret = 1;
	//a = NULL;
	while (ret > 0)
	{
		ret = read(1, &a, 9);
		printf("%d\n", ft_strlen(a));
	}
	return (0);
}
