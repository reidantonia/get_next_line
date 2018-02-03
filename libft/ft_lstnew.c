/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:20:09 by areid             #+#    #+#             */
/*   Updated: 2017/11/18 19:55:37 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*str;

	str = (t_list*)malloc(sizeof(t_list));
	if (str == NULL)
		return (NULL);
	if (!content)
	{
		str->content = NULL;
		str->content_size = 0;
	}
	else
	{
		str->content = ft_strdup(content);
		str->content_size = content_size;
	}
	str->next = NULL;
	return (str);
}
