/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 17:17:34 by ddufour           #+#    #+#             */
/*   Updated: 2016/07/25 19:06:20 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *str;

	if ((str = (char*)ft_memalloc(sizeof(char) * n + 1)) == NULL)
		return (NULL);
	str = (char*)ft_memcpy(str, s1, n);
	return (str);
}
