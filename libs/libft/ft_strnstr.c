/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:29:00 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/08 14:42:53 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		a;
	size_t	j;

	a = 0;
	if (!little[a])
		return ((char *)big);
	j = ft_strlen(little);
	while (big[a] && len-- >= j)
	{
		if (ft_strncmp(big + a, little, j) == 0)
			return ((char *)big + a);
		a++;
	}
	return (NULL);
}
