/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:38:08 by areid             #+#    #+#             */
/*   Updated: 2017/11/19 01:12:21 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*link;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = (*f)(lst);
	if (!(new_list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	link = new_list;
	while (lst)
	{
		tmp = (*f)(lst);
		link->next = ft_lstnew(tmp->content, tmp->content_size);
		lst = lst->next;
		link = link->next;
	}
	return (new_list);
}
