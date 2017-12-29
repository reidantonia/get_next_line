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

int unescape(char *str)
{
		static const char escape[256] = {
				['a'] = '\a',        ['b'] = '\b',        ['f'] = '\f',
				['n'] = '\n',        ['r'] = '\r',        ['t'] = '\t',
				['v'] = '\v',        ['\\'] = '\\',       ['\''] = '\'',
				['"'] = '\"',        ['?'] = '\?',
		};

		char *p = str;      /* Pointer to original string */
		char *q = str;      /* Pointer to new string; q <= p */

		while (*p) {
				int c = *(unsigned char*) p++;

				if (c == '\\') {
						c = *(unsigned char*) p++;
						if (c == '\0') break;
						if (escape[c]) c = escape[c];
				}
				*q++ = c;    
		}
		*q = '\0';
		return (q - str);
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
		while (str[i] != '\n')
				i++;
		ret = ft_strnew(i - 1);
		i = 0;
		while (str[i] != '\n')
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
				return (str);
		while (str[i] != '\n')
				i++;
		ret = ft_strsub(str, i + 1, ft_strlen(str) - 1); 
		return (ret);
}

int			get_next_line(const int fd, char **line)
{
		char buf[BUFF_SIZE + 1];
		static char *str;
		char *tmp;
		ssize_t ret;

		if (BUFF_SIZE < 1 || !line || (fd < 0))
				return (-1);
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
		printf("ret is %lu\n*str is \n\n", ret);fflush(stdout);
				if (ret == -1)
						return (-1);
				buf[BUFF_SIZE] = '\0';
				unescape(buf);
				if (!str)
						str = ft_strdup(buf);
				else
						str = ft_strjoin(str, buf);
				if (ft_check_line((const char*)str))
				{
						*line = ft_trim_line(str);
						tmp = ft_strdup(str);
						ft_strclr(str);
						str = ft_get_remainder(tmp);
						return(1);
				}
		}
		*line = str;
		return (0);
}
