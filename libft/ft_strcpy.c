/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 09:02:31 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 16:05:11 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (src[counter])
		counter++;
	while (i < counter)
	{
		dest[i] = src[i];
		i++;
	}
	dest[counter] = '\0';
	return (dest);
}
