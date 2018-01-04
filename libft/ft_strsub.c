/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:29:37 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/21 16:09:51 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
		char	*fresh;
		size_t	i;

		fresh = ft_strnew(len);
		if (fresh == NULL)
				return (NULL);
		i = 0;
		while (i < len)
		{
				fresh[i] = s[start];
				i++;
				start++;
		}
		return (fresh);
}
