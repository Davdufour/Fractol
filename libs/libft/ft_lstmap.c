/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:28:48 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/24 17:17:41 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!lst && !f)
		return (NULL);
	new = f(lst);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = new->next;
	}
	return (new);
}
