/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 00:19:53 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/05 00:03:48 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcountch(const char *s, size_t n)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	while (n > i)
	{
		c += s[i];
		i++;
	}
	return (c);
}
