/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:27:55 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/07 14:41:34 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	char *t_dst;
	char *t_src;

	t_src = (char*)src;
	t_dst = (char*)dst;
	while (len > 0 && *t_src != c)
	{
		len--;
		*t_dst++ = *t_src++;
	}
	if (len > 0)
	{
		*t_dst++ = *t_src++;
		return ((void*)t_dst);
	}
	else
		return (NULL);
}
