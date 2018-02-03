/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:41:09 by areid             #+#    #+#             */
/*   Updated: 2017/11/18 19:07:13 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_len;
	int				x;
	int				ret;

	i = 0;
	x = 0;
	if (size == 0)
		return ((size_t)ft_strlen(src));
	i = ft_strlen(dest);
	dest_len = i;
	while (src[x] != '\0' && (i < size - 1))
	{
		dest[i] = src[x];
		x++;
		i++;
	}
	dest[i] = '\0';
	while (src[x] != '\0')
		x++;
	if (dest_len < size)
		ret = x + dest_len;
	else
		ret = x + size;
	return ((size_t)ret);
}
