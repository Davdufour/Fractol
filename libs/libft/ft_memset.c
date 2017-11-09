/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 10:35:47 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/10 14:35:52 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp;

	if (len != 0)
	{
		tmp = (unsigned char*)b;
		while (len--)
			*tmp++ = (unsigned char)c;
	}
	return (b);
}
