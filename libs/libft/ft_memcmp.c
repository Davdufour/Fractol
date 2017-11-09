/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:00:39 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/07 15:06:04 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	if (!n)
		return (0);
	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while (*t_s1 == *t_s2 && n > 0)
	{
		t_s1++;
		t_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*t_s1 - *t_s2);
}
