/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 09:37:13 by areid             #+#    #+#             */
/*   Updated: 2017/11/28 09:37:15 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

//#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int get_next_line(const int fd, char **line);

#endif // GET_NEXT_LINE_H
