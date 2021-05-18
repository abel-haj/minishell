#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"


char	ft_lastchr(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = ft_strlen(str);
	return (str[i - 1]);
}

char	*ft_concat(char *str, char c)
{
	char	*new_str;
	char	*tmp;
	size_t	len;
	size_t	i;

	if ((int)c < 0)
		return (str);
	if (str == NULL)
		len = 0;
	else
		len = ft_strlen(str);

	new_str = malloc(len + 2);

	ft_strcpy(new_str, str);
	new_str[len] = c;
	new_str[len + 1] = '\0';

	return (new_str);
}

char	*ft_cleanstr(char *str)
{
	char	*new_str;
	int		w_quote;
	size_t	i;

	new_str = NULL;
	w_quote = 0;
	i = 0;

/*
''""
	0 = none
	' = 1
	" = 2
*/
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (w_quote == 0)
				w_quote = 1;
			else if (w_quote == 1)
				w_quote = 0;
			else if (w_quote == 2)
				new_str = ft_concat(new_str, str[i]);
		}
		else if (str[i] == '"')
		{
			if (w_quote == 0)
				w_quote = 2;
			else if (w_quote == 1)
				new_str = ft_concat(new_str, str[i]);
			else if (w_quote == 2)
				w_quote = 0;
		}
		else
		{
			if (str[i] == ' ')
			{
				if (w_quote == 1 || w_quote == 2)
					new_str = ft_concat(new_str, str[i]);
				else
					if (ft_lastchr(new_str) != ' ')
						new_str = ft_concat(new_str, str[i]);
			}
			else
				new_str = ft_concat(new_str, str[i]);
		}
		i++;
	}
	return (new_str);
}

int		main()
{
	char	*b;
	char	*c;

	// b = NULL;
	// c = getcwd(b, 0);
	// printf("Current dir : %s\n", c);
	// printf("%s\n", b);
	// free(b);
	// free(c);
	// getchar();
	// "str"

	printf("|%s|", ft_cleanstr("    \'str str    str\' \"|   |\"    "));
	return 0;
}
