/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:37:13 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/24 18:53:26 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;

	while (*alst)
	{
		list = *alst;
		*alst = (*alst)->next;
		del(list->content, list->content_size);
		free(list);
		list = NULL;
	}
}
