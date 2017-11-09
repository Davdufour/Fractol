/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:15:10 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/25 17:09:36 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputendl(t_list *lst)
{
	while (lst)
	{
		ft_putendl((char*)lst->content);
		lst = lst->next;
	}
}
