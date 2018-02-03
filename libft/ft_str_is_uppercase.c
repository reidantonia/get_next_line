/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:06:25 by areid             #+#    #+#             */
/*   Updated: 2017/08/09 18:12:39 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int counter;

	counter = 0;
	if (str == '\0')
		return (1);
	while (str[counter] != '\0')
	{
		if ((str[counter] < 'A') || (str[counter] > 'Z'))
			return (0);
		else
			counter++;
	}
	return (1);
}
