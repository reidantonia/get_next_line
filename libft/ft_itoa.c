/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:56:27 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 01:05:38 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdig(unsigned int number)
{
	int		digits;

	digits = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number = number / 10;
		digits++;
	}
	return (digits);
}

static char	*ft_fill_a(unsigned int n, char *str, int digits, int neg_flag)
{
	int		ip;

	if (n == 0)
		str[0] = '0';
	while (digits > 0)
	{
		ip = n % 10 + '0';
		str[digits - 1] = ip;
		digits--;
		n = n / 10;
	}
	if (neg_flag)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int nb)
{
	char			*str;
	int				digits;
	int				neg_flag;
	unsigned int	n;

	neg_flag = 0;
	if (nb < 0)
	{
		n = -1 * (unsigned int)nb;
		neg_flag = 1;
	}
	else
		n = nb;
	digits = ft_countdig(n);
	if (neg_flag)
		digits = digits + 1;
	str = (char*)malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	str = ft_fill_a(n, str, digits, neg_flag);
	return (str);
}
