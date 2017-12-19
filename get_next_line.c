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
	ssize_t ret;
	count = 0;

	while ((ret = read(fd, &c, 1)) && (c != 10))
	{
		printf("%c", c);
		count++;
	}
	printf("\n");
	printf("Ret is %lu\nCount is %d\n",ret, count);
	
	if (ret == 1)
		return (1);
	//	if (ret == EOF)
	//	return (0);
	else
		return (-1);
}
