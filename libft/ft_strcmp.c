/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:35:39 by areid             #+#    #+#             */
/*   Updated: 2017/11/18 12:36:35 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *f1;
	const unsigned char *f2;

	f1 = (const unsigned char*)s1;
	f2 = (const unsigned char*)s2;
	while (*f1 == *f2 && ((*f1 && *f2) != '\0'))
	{
		f1++;
		f2++;
	}
	return (*f1 - *f2);
}
