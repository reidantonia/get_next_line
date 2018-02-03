/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:40:21 by areid             #+#    #+#             */
/*   Updated: 2018/02/03 10:40:24 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_remp(char *str, int i, char const *s2)
{
	int	b;

	b = 0;
	while (s2[b] != '\0')
	{
		str[i] = s2[b];
		b++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_strnew(len + 1);
	if (str)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		str = ft_remp(str, i, s2);
		return (str);
	}
	return (0);
}
