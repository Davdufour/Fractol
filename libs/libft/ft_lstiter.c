/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:17:19 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/24 16:56:27 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	f(lst);
	if (lst->next)
		ft_lstiter(lst->next, f);
}
