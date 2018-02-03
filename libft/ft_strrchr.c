/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:19:53 by areid             #+#    #+#             */
/*   Updated: 2017/11/18 13:48:20 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		length;

	length = 0;
	while (str[length] != '\0')
		length++;
	length++;
	while (length--)
	{
		if (str[length] == c)
			return ((char*)(str + length));
	}
	return (NULL);
}
