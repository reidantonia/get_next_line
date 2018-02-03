/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:04:43 by areid             #+#    #+#             */
/*   Updated: 2017/11/18 22:15:20 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*chain;

	chain = *alst;
	while (chain)
	{
		tmp = chain->next;
		(*del)(chain->content, chain->content_size);
		free(chain);
		chain = tmp;
	}
	*alst = NULL;
}
