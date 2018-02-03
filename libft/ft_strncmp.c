/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:30:18 by areid             #+#    #+#             */
/*   Updated: 2017/11/18 12:29:55 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *f1;
	const unsigned char *f2;
	unsigned int		i;

	f1 = (const unsigned char *)s1;
	f2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (f1[i] == f2[i] && ((f1[i] && f2[i]) != '\0') && (i < n))
		i++;
	if (i == n)
		return (f1[i - 1] - f2[i - 1]);
	return (f1[i] - f2[i]);
}
