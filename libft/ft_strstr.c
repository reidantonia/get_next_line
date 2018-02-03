/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:46:13 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 16:03:35 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	str = (char*)s;
	if (*to_find == '\0')
		return (str);
	while (str[x] != '\0')
	{
		y = 0;
		while (str[x + y] == to_find[y])
		{
			y++;
			if (to_find[y] == '\0')
				return (str + x);
		}
		x++;
	}
	return (0);
}
