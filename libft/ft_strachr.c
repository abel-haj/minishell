/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strachr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:37:19 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/27 22:20:23 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strachr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && c)
	{
		if (s[i] == (unsigned char)c)
			return (s + i + 1);
		i++;
	}
	return (NULL);
}
