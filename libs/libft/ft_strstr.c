/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:43:02 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/08 15:10:18 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		a;

	a = 0;
	if (!big[a] && !little[a])
		return ((char*)big);
	while (big[a])
	{
		if (ft_memcmp(big + a, little, ft_strlen(little)) == 0)
			return ((char*)big + a);
		a++;
	}
	return (NULL);
}
