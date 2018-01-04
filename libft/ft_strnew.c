/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:45:15 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/21 08:22:43 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
		char	*str;
		char	*p;

		str = (char*)malloc((size + 1) * sizeof(char));
		if (str == NULL)
				return (NULL);
		p = str;
		while (size)
		{
				*p++ = '\0';
				size--;
		}
		*p = '\0';
		return (str);
}

