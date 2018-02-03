/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:56:50 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 16:00:07 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int		counter;
	size_t	i;

	counter = 0;
	if (src == '\0' && dest == '\0')
		return (0);
	while (dest[counter] != '\0')
		counter++;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[counter] = src[i];
		counter++;
		i++;
	}
	dest[counter] = '\0';
	return (dest);
}
