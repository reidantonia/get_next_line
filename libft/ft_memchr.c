/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:03:46 by areid             #+#    #+#             */
/*   Updated: 2017/11/07 18:04:53 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*str_str;
	char	to_find;

	str_str = (char*)str;
	to_find = (char)c;
	while (n > 0)
	{
		if (*str_str == to_find)
			return ((void*)str_str);
		str_str++;
		n--;
	}
	return (NULL);
}
