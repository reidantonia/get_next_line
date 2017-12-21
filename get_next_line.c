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
#include <stdio.h>

static int		check_line(char *str)
{
		int i;

		i = 0;
		while (str)
		{
				if (str[i] == '\n')
						return (1);
				i++;
		}
		return (0);
}

static char		*trim_line(char *str)
{
		char	*ret;
		int		i;

		i = 0;
		while (str[i] != '\n')
				i++;
		ret = ft_strnew(i);
		i = 0;
		while (str[i] != '\n')
		{
				ret[i] = str[i];
				i++;
		}
		ret[i] = '\0';
		return (ret);
}

int			get_next_line(const int fd, char **line)
{
		char buf[BUFF_SIZE + 1];
		char *str;
		char c;
		ssize_t ret;
		
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
				if (ret == -1)
						return (-1);
				buf[BUFF_SIZE] = '\0';
				if (check_line(buf))
				{
						*line = trim_line(buf);
						return (0);
				}
				else
				{
						str = ft_strjoin(str, buf);
				}
				if (check_line(buf))
				{
						*line = trim_line(buf);
						return (0);
				}
				while (buf)
						buf[i++] = '\0';
				i++;
		}
		if (ret == 1)
				return (1);
		//	if (ret == EOF)
		//	return (0);
		else
				return (-1);
}
