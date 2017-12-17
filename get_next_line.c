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

int get_next_line(const int fd, char **line)
{
	int result;
int EOF;
	char buffer[BUFFER_SIZE];
EOF = 5;
	if (fd == 1)
	{
		while (**line != '\n' || **line != EOF)
			line++;
		if (**line == '\0')
			return (1);
		if (**line != EOF)
			return (0);
		else
			return (-1);
	}
//result = 1;
	return (result);
}
