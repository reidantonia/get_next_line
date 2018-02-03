/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:05:37 by areid             #+#    #+#             */
/*   Updated: 2017/11/18 18:41:47 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	char			*dst;
	const char		*src;
	unsigned int	x;

	dst = (char*)str1;
	src = (const char*)str2;
	x = 0;
	while (x < n)
	{
		dst[x] = src[x];
		if (src[x] == (const char)c)
			return (dst + x + 1);
		x++;
	}
	return (NULL);
}
