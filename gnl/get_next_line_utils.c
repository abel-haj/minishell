/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:42:37 by abel-haj          #+#    #+#             */
/*   Updated: 2020/02/20 03:03:00 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int			ft_strindof(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str_cpy;

	i = 0;
	str_cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (str_cpy == NULL)
		return (NULL);
	while (s1[i])
	{
		str_cpy[i] = s1[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_string = (char *)malloc(len_s1 + len_s2 + 1);
	if (new_string == NULL)
		return (NULL);
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			new_string[i] = s1[i];
		else
			new_string[i] = s2[i - len_s1];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
