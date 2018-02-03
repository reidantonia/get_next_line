/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:52:22 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 11:56:41 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *str, char c)
{
	int		wc;
	char	*p1;
	char	*p2;

	p1 = (char*)str;
	wc = 0;
	while (*p1 != '\0')
	{
		if (*p1 != c)
		{
			p2 = p1;
			while (*p2 != '\0' && *p2 != c)
				p2++;
			wc++;
			p1 = p2;
		}
		else
		{
			p1++;
		}
	}
	return (wc);
}

static int		ft_wl(char const *str, char c)
{
	int		length;

	length = 0;
	while (*str != '\0' && *str != c)
	{
		length++;
		str++;
	}
	return (length);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**array;
	int		wc;
	int		i;

	if (!str)
		return (NULL);
	wc = ft_countwords(str, c);
	i = 0;
	array = (char**)malloc(sizeof(char*) * (wc + 1));
	if (!array)
		return (NULL);
	while (i < wc)
	{
		while (*str == c && *str != '\0')
			str++;
		array[i] = ft_strsub((const char *)str, 0, (unsigned int)ft_wl(str, c));
		str = str + ft_wl(str, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
