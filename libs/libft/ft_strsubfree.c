/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:54:36 by ddufour           #+#    #+#             */
/*   Updated: 2016/09/14 17:15:07 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	if ((str = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	str = ft_memcpy(str, s + start, len);
	free((char*)s);
	return (str);
}
