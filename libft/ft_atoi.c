/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:20:37 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 15:29:36 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *s)
{
	int				result;
	int				i;
	int				is_negative;

	i = 0;
	result = 0;
	is_negative = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
			|| s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		i++;
		is_negative = -1;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		result = result * 10 + s[i] - 48;
		i++;
	}
	return (result * is_negative);
}
