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
		ret = ft_strsub(str, i + 1, ft_strlen(str) - i);
		return (ret);
}

static unsigned int	ft_strclen(char *save)
{
		unsigned int	i;

		i = 0;
		while (save[i] != '\n' && save[i] != '\0')
				i++;
		return (i);
}


static char			*ft_chrandcpy(char *save)
{
		if (ft_strchr(save, '\n'))
		{
				ft_strcpy(save, ft_strchr(save, '\n') + 1);
				return (save);
		}
		if (ft_strclen(save) > 0)
		{
				ft_strcpy(save, ft_strchr(save, '\0'));
				return (save);
		}
		return (NULL);
}
static char			*ft_strrejoin(char *s1, char *s2, size_t len)
{
		char		*str;
		int			nb;
		char		*tmp;

		nb = ft_strlen(s1) + ++len;
		str = ft_strnew(nb);
		tmp = str;
		while (*s1)
				*str++ = *s1++;
		while (*s2 && --len > 0)
				*str++ = *s2++;
		*str = '\0';
		return (str - (str - tmp));
}

int			get_next_line(const int fd, char **line)
{
		char buf[BUFF_SIZE + 1];
		static char *str[1];
		char *tmp;
		char *ptr;
		ssize_t ret;

		if (BUFF_SIZE < 1 || !line || (fd < 0))
				return (-1);
		while (!(ft_strchr(str[1], '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
				buf[ret] = '\0';
				unescape(buf);
				ptr = str[1];
				str[1] = ft_strrejoin(ptr, buf, ret);
				free(ptr);
		}
			*line = ft_strsub(str[1], 0, ft_strclen(str[1]));
		if (ft_chrandcpy(str[1]) == NULL)
				return (0);
		return (1);
}
