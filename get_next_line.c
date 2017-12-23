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
						return (i);
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
		//printf("ret IS\n\n<<%s>>\n\n", ret);
		return (ret);
}

int			get_next_line(const int fd, char **line)
{
		char buf[BUFF_SIZE + 1];
		static char *str;
		char *tmp;
		ssize_t ret;
		int index;
		
		index = 0;
		printf("\n---->BUF BEFORE <<%s>>\n\n", str);
		str = ft_memalloc(1);
		//ptr = buf;
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
				if (ret == -1)
						return (-1);
				buf[BUFF_SIZE] = '\0';
				str = ft_strjoin(str, buf);
				if ((index = check_line(str)) != BUFF_SIZE)
				{
						*line = ft_trim_line(buf);
						tmp = ft_strdup(str);
						ft_strclr(str);
						str = ft_strnew(BUFF_SIZE - index);
						str = ft_prep_next(tmp);
						return(1);
				}
				//ft_strclr(buf);
		}
		if (ret == 1)
				return (1);
		//	if (ret == EOF)
		//	return (0);
		else

				return (-1);
}
