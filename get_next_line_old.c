/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 09:36:52 by areid             #+#    #+#             */
/*   Updated: 2017/11/28 09:37:07 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcomb(char *s1, char *s2)
{
		char	*fresh;
		size_t	i;
		size_t	j;

		fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (fresh == NULL)
				return (NULL);
		j = 0;
		i = 0;
		while (s1[i])
				fresh[j++] = s1[i++];
		i = 0;
		while (s2[i])
				fresh[j++] = s2[i++];
		return (fresh);
}

static int		ft_check_line(const char *str)
{
		int i;

		i = 0;
		while (str && str[i] != '\0')
		{
				if (str[i] == '\n')
						return (1);
				i++;
		}
		return (0);
}

static char		*ft_trim_line(char *str)
{
		char	*ret;
		int		i;

		i = 0;
		while (str[i] != '\n' && str[i] != '\0')
				i++;
		ret = ft_strnew(i);
		i = 0;
		while (str[i] != '\n' && str[i] != '\0')
		{
				ret[i] = str[i];
				i++;
		}
		return (ret);
}

static char		*ft_get_remainder(char *str)
{
		int		i;
		char	*ret;

		i = 0;
		if (str[i] == '\0')
				return (NULL);
		while (str[i] != '\n' && str[i] != '\0')
				i++;
		ret = ft_strsub(str, i + 1, ft_strlen(str) - i);
		free(str);
		return (ret);
}

int					get_next_line(int const fd, char **line)
{
		char		buf[BUFF_SIZE + 1];
		static char	*str;
		int			ret;
		char		*ptr;

		if ((read(fd, buf, 0) < 0) || BUFF_SIZE < 1 || !line || (fd < 0))
				return (-1);
		if (!str)
		{
				str = ft_strnew(0);
				if (str == NULL)
						return (-1);
		}
		while (!(ft_check_line((const char*)str)) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
				buf[ret] = '\0';
				ptr = str;
				str = ft_strcomb(ptr, buf);
				free(ptr);
		}
		*line = ft_trim_line(str);
		ptr = str;
		if ((str = ft_get_remainder(ptr)) == NULL)
		{
				free(ptr);
				return (0);
		}
		return (1);
}
