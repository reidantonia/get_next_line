/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 19:08:33 by areid             #+#    #+#             */
/*   Updated: 2017/08/09 12:12:10 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int counter;

	counter = 0;
	if (str == '\0')
		return (1);
	while (str[counter] != '\0')
	{
		if ((str[counter] < '0') || (str[counter] > '9'))
			return (0);
		else
			counter++;
	}
	return (1);
}
