/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:09:35 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 01:37:38 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int counter;

	counter = 0;
	if (str == '\0')
		return (1);
	while (str[counter] != '\0')
	{
		if (str[counter] < ' ' || str[counter] == 127)
			return (0);
		else
			counter++;
	}
	return (1);
}
