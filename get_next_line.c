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

int get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	int count;
	char c;
	int i;
	ssize_t ret;
	count = 0;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
			return (-1);
		buf[BUFF_SIZE] = '\0';
		printf("Ret is '%lu'\nfd is '%d'\n",ret,fd);
		printf("%d is <<%s>>\n\n", i, buf);
		i++;
	}

	printf("\n\nTHe result is:\n<<%s>>", buf);
	/* {
	   printf("%c", c);
	   count++;
	   }*/
	*line = ft_strdup(buf);
	if (ret == 1)
		return (1);
	//	if (ret == EOF)
	//	return (0);
	else
		return (-1);
}
