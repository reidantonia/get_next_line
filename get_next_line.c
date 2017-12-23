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

static char		*ft_trim_line(char *str)
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

static char		*ft_prep_next(char *str)
{
	int		i;
	char	*ret;
	i = 0;

	while (str[i] != '\n')
		i++;
	ret = ft_strsub(str, i + 1, ft_strlen(str) - 1); 
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
		char buf[BUFF_SIZE + 1];
		char *str;
		char *tmp;
		char c;
		ssize_t ret;
		
		str = ft_memalloc(1);
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
				if (ret == -1)
						return (-1);
				buf[BUFF_SIZE] = '\0';
				str = ft_strjoin(str, buf);
				if (check_line(str))
				{
						*line = ft_trim_line(buf);
						printf("BUF IS\n\n<<%s>>\n\n",buf);
						*buf = *buf - 3;
						//tmp = ft_prep_next(buf);
						//ft_strclr(buf);
						//buf = ft_strdup(tmp);
						return(1);
				}
		}
		if (ret == 1)
				return (1);
		//	if (ret == EOF)
		//	return (0);
		else
				return (-1);
}
