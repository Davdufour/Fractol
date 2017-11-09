/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:12:56 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/07 14:53:47 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	int				a;

	a = -1;
	tmp = (unsigned char *)s;
	while (n--)
		if (tmp[++a] == (unsigned char)c)
			return ((void *)s + a);
	return (NULL);
}
