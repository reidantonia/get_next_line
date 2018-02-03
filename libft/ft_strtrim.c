/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:40:06 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 01:46:52 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		x;
	int		y;
	int		i;
	char	*str;
	int		strl;

	x = 0;
	if (!s)
		return (NULL);
	y = ft_strlen(s) - 1;
	while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n')
		x++;
	while (s[y] == ' ' || s[y] == '\t' || s[y] == '\n')
		y--;
	if ((strl = (y - x) + 1) < 0)
		strl = 0;
	if (x == 0 && (y == (int)ft_strlen(s) - 1))
		return (ft_strdup(s));
	if ((str = ft_strnew(strl)) == NULL)
		return (NULL);
	i = 0;
	while (x <= y)
		str[i++] = s[x++];
	str[y + 1] = '\0';
	return (str);
}
