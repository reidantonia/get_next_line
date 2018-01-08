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

static int		ft_chkl(const char *str)
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

char *ft_really_get(int const fd, char **line, char **str)
{
		char		buf[BUFF_SIZE + 1];
		int ret;
		char *ptr;
		while (!(ft_chkl((const char*)str[fd])) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
				buf[ret] = '\0';
				ptr = str[fd];
				str[fd] = ft_strjoin(ptr, buf);
				free(ptr);
		}
		*line = ft_trim_line(str[fd]);
		return (str[fd]);
}


int					get_next_line(int const fd, char **line)
{
		char		buf[BUFF_SIZE + 1];
		static char	*str[10];
		//int			ret;
		char		*ptr;

		if ((read(fd, buf, 0) < 0) || BUFF_SIZE < 1 || !line || (fd < 0))
				return (-1);
		if (!str[fd])
		{
				str[fd] = ft_strnew(0);
				if (str[fd] == NULL)
						return (-1);
		}
		str[fd] = ft_really_get(fd, line, str);
		ptr = str[fd];
		if ((str[fd] = ft_get_remainder(ptr)) == NULL)
		{
				free(ptr);
				return (0);
		}
		return (1);
}
